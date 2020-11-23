// build shell: 
//    g++ cpp11_03_final_override.cpp --std=c++11
class Parent {
  virtual void watchTv(int);
};

class Child: Parent {
  virtual void watchTv(int) override; // 合法
  virtual void watchTv(float) override; // 非法, 父类没有此虚函数
};

class Parent2 {
  virtual void eat() final;
};

class Child2 final : Parent2 {
}; // 合法

class Grandson : Child2 {
}; // 非法, Child 已 final

class Child3 : Parent2 {
  void eat() override; // 非法, foo 已 final
};

int main() {
  return 0;
}