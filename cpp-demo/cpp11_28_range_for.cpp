// build shell:
// g++ cpp11_28_range_for.cpp --std=c++11
#include <iostream>

using namespace std;

int main() {
  int nums[] = { 0, 1, 2, 3, 4};

  for (auto num : nums) {
    cout << num << endl;
  }

  return 1;
}