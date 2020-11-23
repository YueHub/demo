// build shell: 
//    g++ cpp11_10_delegating_inherited_constructors.cpp --std=c++11
#include <iostream>

using namespace std;

class Parent {
public:
  int value1;
  int value2;

  Parent() {
    value1 = 1;
  }

  Parent(int value) : Parent() { // 委托 Parent() 构造函数
    value2 = value;
  }
};

class Child : public Parent {
public:
  using Parent::Parent; // 继承构造
};

int main() {
  Child child(2);

  cout << child.value1 << endl;
  cout << child.value2 << endl;

  return 0;
}