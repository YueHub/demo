#include <iostream>

using namespace std;

// ⼀元左折叠
template<typename... Args>
auto sub_val_left(Args&&... args) {
  return (... - args);
}

// 一元右折叠
template<typename... Args>
auto sub_val_right(Args&&... args) {
  return (args - ...);
}

// 二元左折叠
template<typename... Args>
auto sub_one_left(Args&&... args) {
  return (1 - ... - args);
}

// 二元右折叠
template<typename... Args>
auto sub_one_right(Args&&... args) {
  return (args - ... - 1);        
}

int main() {
  cout << sub_val_left(2, 3, 4) << endl;

  cout << sub_val_right(2, 3, 4) << endl;

  cout << sub_one_left(2, 3, 4) << endl;

  cout << sub_one_right(2, 3, 4) << endl;
  
  return 0;
}