#include <iostream>

using namespace std;

class HasPtrMem1 {
 public:
  HasPtrMem1() : d(new int(0)) {}
  ~HasPtrMem1() { delete d; }
  int* d;
};

class HasPtrMem2 {
 public:
  HasPtrMem2() : d(new int(0)) {}
  HasPtrMem2(const HasPtrMem2& h) :
      d(new int(*h.d)) {}
  ~HasPtrMem2() { delete d; }
  int* d;
};

int getVal() {
  return 1;
}

void processValue(int& a) {
  cout << "lvalue" << endl; 
}
void processValue(int&& a) {
  cout << "rvalue" << endl;
}
void processValue(const int& a) {
  cout << "const int&" << endl;
}


template <typename T>
void forwardValue1(T& val) {
  // 右值参数会变成左值
  processValue(val);
}

template <typename T>
void forwardValue1(const T& val) {
  processValue(val); // 参数都变成常量左值引用了
}

template <typename T>
void forwardValue2(T&& val) {
  // 照参数本来的类型进行转发
  processValue(std::forward<T>(val)); 
}

int main() {

  // 左值与右值
  int i = 0;
  int* p_i = &i; // 可通过 & 取出地址，固 i 为左值
  cout << p_i << endl;

  // int* p_i_plus = &(i+1); // 非法, i+1 为右值
  // int* p_i_const = &(0); // 非法，0 为右值

  // 左值引用
  int j = 0;
  int &ref_j = j; // ref_j 为左值引用

  // int &ref_j_plus = j + 1; // 非法，左值引用不能作用于右值
  // int &ref_const = 0; // 非法，左值引用不能作用于右值

  // 右值引用
  int &&ref_k_plus = (i + 1); // ref_k_plus 为右值引用，它绑定了右值 i+1
  int &&ref_k = 0; // ref_k 为右值引用，它绑定了右值 0

  // 指针成员浅拷贝
  // HasPtrMem1 a1;
  // HasPtrMem1 b1(a1);

  // cout << *a1.d << endl;
  // cout << *b1.d << endl;

  // 指针成员深拷贝
  HasPtrMem2 a2;
  HasPtrMem2 b2(a2);

  cout << *a2.d << endl;
  cout << *b2.d << endl;

  // 
  forwardValue1(i); //传入左值
  forwardValue1(0); //传入右值

  forwardValue2(i); //传入左值
  forwardValue2(0); //传入右值

  return 0;
}