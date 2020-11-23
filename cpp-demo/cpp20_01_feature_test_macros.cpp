#include <iostream>

using namespace std;

int main() {
  cout << __has_cpp_attribute(fallthrough) << endl;

  cout << __has_cpp_attribute(fallthrough111) << endl;
  return 0;
}