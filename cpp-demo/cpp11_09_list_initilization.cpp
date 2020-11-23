#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

int arr1[3] = { 1, 2, 3 };
long arr2[] = { 1, 3, 2, 4 };

struct A {
    int x;
    int y;
} a = { 1, 2 };

class Dog {
 public:
  Dog(string name, int age) {
   cout << name << " ";
   cout << age << endl; 
  }

  Dog(initializer_list<int> list) {
    for (initializer_list<int>::iterator it = list.begin(); 
          it != list.end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;
  }
};

Dog getDefaultDog() {
  return {"default", 3};
}

void watch(Dog dog) {
  cout << "watch" << endl;
}

int main() {
  Dog dog1 = {"cat1", 1};
  Dog dog2 {"cat2", 2};

  Dog dog3 = {1, 2, 3, 4, 5};

  getDefaultDog();

  watch({"watch_dog", 4});

  return 0;
}
