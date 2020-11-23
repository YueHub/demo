#include <iostream>

using namespace std;

int main() {
  int a = 1;

  // 值捕获
  auto f1 = [a] () { cout << a << endl; };
  a = 2;
  f1();

  // 引用捕获
  auto f2 = [&a] () { cout << a << endl; };
  a = 3;
  f2();

  cout << a << endl;

  auto lambda1 = [value = 1 + a] {return value;};

  return 0;
}