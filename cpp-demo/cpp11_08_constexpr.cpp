#include <iostream>

using namespace std;

constexpr int getLen() {
  return 4;
}

int main() {
  constexpr int a = 1 + 2 + 3 + getLen();
  char arr[a];

  cout << sizeof(arr) / sizeof(arr[0]) << endl;
  return 0;
}

