#include <iostream>

using namespace std;

int main(void) {
  
  for (int i = 0; i < 10; i++) {
    // init for if
    if (int count = 5; i > count) {
      cout << i << endl;
    }
    
    // init for switch
    switch (const int plus = i + 10; plus) {
      case 19:
        cout << "hello, plus" << endl;
        break;
      default:
        break;
    }
  }

  return 0;
}
