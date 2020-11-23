#include <iostream>

using namespace std;

struct A {
  char a;
  int b;
};

struct alignas(std::max_align_t) B {
  char a;
  int b;
  float c;
};

int main() {
  cout << alignof(A) << endl;
  cout << alignof(B) << endl;

  return 0;
}