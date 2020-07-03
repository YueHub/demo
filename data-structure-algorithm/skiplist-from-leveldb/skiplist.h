// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef STORAGE_LEVELDB_DB_SKIPLIST_H_
#define STORAGE_LEVELDB_DB_SKIPLIST_H_

// Thread safety
// -------------
//
// Writes require external synchronization, most likely a mutex.
// Reads require a guarantee that the SkipList will not be destroyed
// while the read is in progress.  Apart from that, reads progress
// without any internal locking or synchronization.
//
// Invariants:
//
// (1) Allocated nodes are never deleted until the SkipList is
// destroyed.  This is trivially guaranteed by the code since we
// never delete any skip list nodes.
//
// (2) The contents of a Node except for the next/prev pointers are
// immutable after the Node has been linked into the SkipList.
// Only Insert() modifies the list, and it is careful to initialize
// a node and use release-stores to publish the nodes in one or
// more lists.
//
// ... prev vs. next pointer ordering ...

#include <atomic>
#include <cassert>
#include <cstdlib>

#include "util/arena.h"
#include "util/random.h"

namespace leveldb {

class Arena;

template <typename Key, class Comparator>
class SkipList {
 private:
  // 跳跃表结点
  struct Node;

 public:
  // Create a new SkipList object that will use "cmp" for comparing keys,
  // and will allocate memory using "*arena".  Objects allocated in the arena
  // must remain allocated for the lifetime of the skiplist object.
  explicit SkipList(Comparator cmp, Arena* arena);

  SkipList(const SkipList&) = delete;
  SkipList& operator=(const SkipList&) = delete;

  // Insert key into the list.
  // REQUIRES: nothing that compares equal to key is currently in the list.
  // 向跳跃表中插入 key
  // 要求：跳跃表不存在于当前 key 相同的元素
  void Insert(const Key& key);

  // Returns true iff an entry that compares equal to key is in the list.
  // 返回跳跃表是否存在该 key
  bool Contains(const Key& key) const;

  // Iteration over the contents of a skip list
  // 跳跃表迭代器
  class Iterator {
   public:
    // Initialize an iterator over the specified list.
    // The returned iterator is not valid.
    explicit Iterator(const SkipList* list);

    // Returns true iff the iterator is positioned at a valid node.
    // 判断当前迭代器是否指向一个有效结点
    bool Valid() const;

    // Returns the key at the current position.
    // REQUIRES: Valid()
    // 返回当前迭代器指向的元素
    const Key& key() const;

    // Advances to the next position.
    // REQUIRES: Valid()
    // 迭代到下一个元素
    void Next();

    // Advances to the previous position.
    // REQUIRES: Valid()
    // 迭代到上一个元素
    void Prev();

    // Advance to the first entry with a key >= target
    // 迭代到第一个 key > target 的元素
    void Seek(const Key& target);

    // Position at the first entry in list.
    // Final state of iterator is Valid() iff list is not empty.
    // 迭代到第一个元素
    void SeekToFirst();

    // Position at the last entry in list.
    // Final state of iterator is Valid() iff list is not empty.
    // 迭代到最后一个元素
    void SeekToLast();

   private:
    const SkipList* list_;
    Node* node_;
    // Intentionally copyable
  };

 private:
  // 跳跃表最大高度（也就是层数）
  enum { kMaxHeight = 12 };

  // 获取当前最大高度
  inline int GetMaxHeight() const {
    return max_height_.load(std::memory_order_relaxed);
  }

  // 创建结点
  Node* NewNode(const Key& key, int height);
  // 获取一个随机高度（相当于结点提升至索引结点的概率）
  int RandomHeight();
  // 判断 key 是否相同
  bool Equal(const Key& a, const Key& b) const { return (compare_(a, b) == 0); }

  // 判断 key 结点 是否在结点 n 之后
  // 大小由 Comparator 比较器确定
  // Return true if key is greater than the data stored in "n"
  bool KeyIsAfterNode(const Key& key, Node* n) const;

  // Return the earliest node that comes at or after key.
  // Return nullptr if there is no such node.
  //
  // If prev is non-null, fills prev[level] with pointer to previous
  // node at "level" for every level in [0..max_height_-1].
  // 寻找大于等于 key 结点的所有结点
  // 如果存在，则通过 prev 返回
  Node* FindGreaterOrEqual(const Key& key, Node** prev) const;

  // Return the latest node with a key < key.
  // Return head_ if there is no such node.
  // 寻找小于 key 的结点
  // 如果不存在这样的结点，则返回 head_ 结点
  Node* FindLessThan(const Key& key) const;

  // Return the last node in the list.
  // Return head_ if list is empty.
  // 返回最后一个结点
  // 如果跳跃表为空，则返回 head_ 结点
  Node* FindLast() const;

  // Immutable after construction
  // 比较器
  Comparator const compare_;
  Arena* const arena_;  // Arena used for allocations of nodes

  // 头结点
  Node* const head_;

  // Modified only by Insert().  Read racily by readers, but stale
  // values are ok.
  // 只会被 Insert() 函数修改
  // 最大高度
  std::atomic<int> max_height_;  // Height of the entire list

  // Read/written only by Insert().
  // 随机数，用于计算随机高度
  Random rnd_;
};

// Implementation details follow
template <typename Key, class Comparator>
struct SkipList<Key, Comparator>::Node {
  explicit Node(const Key& k) : key(k) {}

  // key 
  Key const key;

  // Accessors/mutators for links.  Wrapped in methods so we can
  // add the appropriate barriers as necessary.
  // 获取当前结点 next_ 数组中第 n 个元素
  // 即当前索引结点链表第 n 个元素
  Node* Next(int n) {
    assert(n >= 0);
    // Use an 'acquire load' so that we observe a fully initialized
    // version of the returned Node.
    return next_[n].load(std::memory_order_acquire);
  }
  // 存储元素到当前索引结点链表第 n 个位置
  void SetNext(int n, Node* x) {
    assert(n >= 0);
    // Use a 'release store' so that anybody who reads through this
    // pointer observes a fully initialized version of the inserted node.
    next_[n].store(x, std::memory_order_release);
  }

  // No-barrier variants that can be safely used in a few locations.
  // 没有内存屏障保护？所以不能保证其线程安全，可用在少数一些场合
  Node* NoBarrier_Next(int n) {
    assert(n >= 0);
    return next_[n].load(std::memory_order_relaxed);
  }
  // 没有内存屏障保护？所以不能保证其线程安全，可用在少数一些场合
  void NoBarrier_SetNext(int n, Node* x) {
    assert(n >= 0);
    next_[n].store(x, std::memory_order_relaxed);
  }

 private:
  // Array of length equal to the node height.  next_[0] is lowest level link.
  // 数组的长度等于结点的高度（即索引结点的层次）
  std::atomic<Node*> next_[1];
};

template <typename Key, class Comparator>
typename SkipList<Key, Comparator>::Node* SkipList<Key, Comparator>::NewNode(
    const Key& key, int height) {
  // 从管理的内存池中分配内存，大小为 Node 结点 + next_ 数组大小（内部存储 height - 1 个 Node 类型指针）
  // 从这里也可以看出比通常的跳跃表实现要省内存
  char* const node_memory = arena_->AllocateAligned(
      sizeof(Node) + sizeof(std::atomic<Node*>) * (height - 1));
  return new (node_memory) Node(key);
}

template <typename Key, class Comparator>
inline SkipList<Key, Comparator>::Iterator::Iterator(const SkipList* list) {
  list_ = list;
  node_ = nullptr;
}

template <typename Key, class Comparator>
inline bool SkipList<Key, Comparator>::Iterator::Valid() const {
  return node_ != nullptr;
}

template <typename Key, class Comparator>
inline const Key& SkipList<Key, Comparator>::Iterator::key() const {
  assert(Valid());
  return node_->key;
}

template <typename Key, class Comparator>
inline void SkipList<Key, Comparator>::Iterator::Next() {
  assert(Valid());
  node_ = node_->Next(0);
}

template <typename Key, class Comparator>
inline void SkipList<Key, Comparator>::Iterator::Prev() {
  // Instead of using explicit "prev" links, we just search for the
  // last node that falls before key.
  assert(Valid());
  node_ = list_->FindLessThan(node_->key);
  if (node_ == list_->head_) {
    node_ = nullptr;
  }
}

template <typename Key, class Comparator>
inline void SkipList<Key, Comparator>::Iterator::Seek(const Key& target) {
  node_ = list_->FindGreaterOrEqual(target, nullptr);
}

template <typename Key, class Comparator>
inline void SkipList<Key, Comparator>::Iterator::SeekToFirst() {
  node_ = list_->head_->Next(0);
}

template <typename Key, class Comparator>
inline void SkipList<Key, Comparator>::Iterator::SeekToLast() {
  node_ = list_->FindLast();
  if (node_ == list_->head_) {
    node_ = nullptr;
  }
}

template <typename Key, class Comparator>
int SkipList<Key, Comparator>::RandomHeight() {
  // Increase height with probability 1 in kBranching
  static const unsigned int kBranching = 4;
  int height = 1;
  // 以 25% 的概率增加高度，为什么不是 50%。空间与时间的考量
  // 从而返回一个范围在 1 ～ kMaxHeight 之间的随机高度
  while (height < kMaxHeight && ((rnd_.Next() % kBranching) == 0)) {
    height++;
  }
  assert(height > 0);
  assert(height <= kMaxHeight);
  return height;
}

template <typename Key, class Comparator>
bool SkipList<Key, Comparator>::KeyIsAfterNode(const Key& key, Node* n) const {
  // null n is considered infinite
  // 判断是否 n->key < key
  return (n != nullptr) && (compare_(n->key, key) < 0);
}

// 搜索大于等于 key 的所有结点
// 大小由 Comparator 来定义
template <typename Key, class Comparator>
typename SkipList<Key, Comparator>::Node*
SkipList<Key, Comparator>::FindGreaterOrEqual(const Key& key,
                                              Node** prev) const {
  Node* x = head_;
  // 获取当前结点的层高
  // 从最上层的索引层开始遍历
  int level = GetMaxHeight() - 1;
  while (true) {
    // 假设 next_ = [*3, *5, *6]
    // 表示该结点：
    // 在第 2 层的下一个索引结点为 6
    // 在第 1 层的下一个索引结点为 5
    // 在第 0 层的下一个结点为 3
    // 那么就可以直接通过 next_[level] 找到下一个索引结点
    Node* next = x->Next(level);
    if (KeyIsAfterNode(key, next)) {  // key 是否在当前结点之后（大小关系由比较器最终确认）
      // Keep searching in this list
      // 继续遍历搜索该层的剩余结点
      x = next;
    } else {  // key 是否在当前结点之后（大小关系由比较器最终确认）
      // 记录结点到 prev 数组
      // prev 数组记录每个索引层次要插入 key 的位置
      if (prev != nullptr) prev[level] = x; prev
      if (level == 0) { // 遍历到 0 层，遍历结束
        return next;
      } else {
        // Switch to next list
        // 进入下一层遍历
        level--;
      }
    }
  }
}

// 搜索所有小于 key 结点的结点
// 大小由 Comparator 定义
template <typename Key, class Comparator>
typename SkipList<Key, Comparator>::Node*
SkipList<Key, Comparator>::FindLessThan(const Key& key) const {
  Node* x = head_;
  int level = GetMaxHeight() - 1;
  while (true) {
    assert(x == head_ || compare_(x->key, key) < 0);
    Node* next = x->Next(level);
    if (next == nullptr || compare_(next->key, key) >= 0) {
      if (level == 0) {
        return x;
      } else {
        // Switch to next list
        level--;
      }
    } else {
      x = next;
    }
  }
}

// 查找最后一个元素
template <typename Key, class Comparator>
typename SkipList<Key, Comparator>::Node* SkipList<Key, Comparator>::FindLast()
    const {
  Node* x = head_;
  int level = GetMaxHeight() - 1;
  while (true) {
    // 迭代该层所有结点
    Node* next = x->Next(level);
    if (next == nullptr) {
      if (level == 0) {
        return x;
      } else {
        // 迭代至下一层
        // Switch to next list
        level--;
      }
    } else {
      x = next;
    }
  }
}

template <typename Key, class Comparator>
SkipList<Key, Comparator>::SkipList(Comparator cmp, Arena* arena)
    : compare_(cmp),
      arena_(arena),
      head_(NewNode(0 /* any key will do */, kMaxHeight)),  // 创建第一个结点，key 为 0，高度为默认的 12 
      max_height_(1),                                       // 最大高度初始化为 1
      rnd_(0xdeadbeef) {                                    // 初始化随机数
  // 
  for (int i = 0; i < kMaxHeight; i++) {
    head_->SetNext(i, nullptr);
  }
}

template <typename Key, class Comparator>
void SkipList<Key, Comparator>::Insert(const Key& key) {
  // TODO(opt): We can use a barrier-free variant of FindGreaterOrEqual()
  // here since Insert() is externally synchronized.
  Node* prev[kMaxHeight];
  // 获取所有大于等于（比较器定义） key 的结点
  // prev 保存各个索引层要插入的前一个结点
  Node* x = FindGreaterOrEqual(key, prev);

  // Our data structure does not allow duplicate insertion
  // 不允许插入重复的元素
  // 那么为空，表示没有 >= key 的结点。要么不等于列表中的所有 key，表示没有重复元素
  assert(x == nullptr || !Equal(key, x->key));
  
  // 生成一个随机高度
  int height = RandomHeight();
  // 如果随机高度比当前最大高度大
  if (height > GetMaxHeight()) {
    // prev 下标从原先的最大 height 到最新的最大 height 之间初始化为 head_
    for (int i = GetMaxHeight(); i < height; i++) {
      prev[i] = head_;
    }
    // It is ok to mutate max_height_ without any synchronization
    // with concurrent readers.  A concurrent reader that observes
    // the new value of max_height_ will see either the old value of
    // new level pointers from head_ (nullptr), or a new value set in
    // the loop below.  In the former case the reader will
    // immediately drop to the next level since nullptr sorts after all
    // keys.  In the latter case the reader will use the new node.
    // 原子操作：保存最新的最大高度
    max_height_.store(height, std::memory_order_relaxed);
  }

  // 创建一个新结点
  x = NewNode(key, height);
  for (int i = 0; i < height; i++) {
    // NoBarrier_SetNext() suffices since we will add a barrier when
    // we publish a pointer to "x" in prev[i].
    // 
    // 插入新结点，即：
    // new_node->next = pre->next;
    // pre->next = new_node;
    x->NoBarrier_SetNext(i, prev[i]->NoBarrier_Next(i));
    prev[i]->SetNext(i, x);
  }
}

// 判断是否存在 key 结点
template <typename Key, class Comparator>
bool SkipList<Key, Comparator>::Contains(const Key& key) const {
  Node* x = FindGreaterOrEqual(key, nullptr);
  if (x != nullptr && Equal(key, x->key)) {
    return true;
  } else {
    return false;
  }
}

}  // namespace leveldb

#endif  // STORAGE_LEVELDB_DB_SKIPLIST_H_
