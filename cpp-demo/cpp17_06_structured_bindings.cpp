#include <iostream>
#include <tuple>

using namespace std;

tuple<int, double, string> f() {
  return make_tuple(1, 2.3, "456");
}

int main() {
  int arr[2] = {1,2};
  // 创建 e[2]
  // 复制 arr 到 e，然后 a1 指代 e[0]，b1 指代 e[1]
  auto [a1, b1] = arr;
  cout << a1 << ", " << b1 << endl;

  // a2 指代 arr[0], b2 指代 arr[1]
  auto& [a2, b2] = arr;
  cout << a2 << ", " << b2 << endl;

  // 结构化绑定 tuple
  auto [x, y, z] = f();
  cout << x << ", " << y << ", " << z << endl;

  return 0;
}