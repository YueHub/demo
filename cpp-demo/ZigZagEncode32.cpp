#include <iostream>
#include <stdint.h>

using namespace std;

// ZigZag 编码
inline uint32_t ZigZagEncode32(int32_t n) {
  // 右移为算数右移
  // 左移时需要先将 n 转成 uint32 类型，防止溢出
  // 当 n 为正数时 result = 2 * n
  // 当 n 为负数时 result = - (2 * n + 1)
  return (static_cast<uint32_t>(n) << 1) ^ static_cast<uint32_t>(n >> 31);
}

int main() {
  uint32_t n = 1;

  while (n != 0) {
    cout << "输入 n(输入 0 结束):" << endl;
    cin >> n;
    cout << "result: " << ZigZagEncode32(n) << endl;
  }
  
  return 0;
}