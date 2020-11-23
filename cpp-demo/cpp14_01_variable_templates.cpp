// build shell:
//    g++ cpp14_01_variable_templates.cpp --std=c++14


#include <iostream>

using namespace std;
template<class T>
constexpr T pi = T(3.1415926535897932385);

int main() {
  cout << pi<int> << endl;

  cout << pi<float> << endl;

  cout << pi<double> << endl;

  return 0;
}