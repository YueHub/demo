#include <iostream>

using namespace std;

int main() {
  enum class Color : char { RED, BLUE };

  Color c = Color::RED;

  return 0;
}