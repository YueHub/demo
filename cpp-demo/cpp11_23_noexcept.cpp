#include <iostream>

using namespace std;

int funcA() {
  return 0;
}

int funcB() noexcept {
  return 0;
}

int main() {
  int a = funcA();
  int b = funcB();

  cout << a << endl;
  cout << b << endl;

  cout << noexcept(funcA()) << endl;
  cout << noexcept(funcB()) << endl;

  return 0;
}