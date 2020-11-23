// build shell:
//   g++ cpp11_01_auto_decltype.cpp --std=c++11
#include <iostream>
using namespace std;

// auto
int AboutAuto() {
  auto a = 10; // 自动推导 a 为 int
  auto b = 10.2; // 自动推导 b 为 double
  auto c = &a; // 自动推导 c 为 int*
  auto d = "xxx"; // 自动推导 d 为 const char*

  return 0;
}

// decltype
int AboutDecltype() {
  int a = 0; 

  decltype(a) b = 1; // b 被推导成了 int
  decltype(10.8) c = 5.5; // c 被推导成了 double
  decltype(c + 100) d; // d 被推导成了 double

  struct { double x; } aa;
  decltype(aa.x) y; // y 的类型是 double（其声明类型）
  decltype(aa) bb; // 推断匿名结构体类型，并声明变量

  return 0;
}

template<typename T, typename U>
auto add(T x, U y) -> decltype(x+y) {
  return x + y;
}

int main() {
  int ans = add(1, 2);
  cout << ans << endl;

  return 0;
}

