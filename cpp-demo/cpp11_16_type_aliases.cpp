#include <iostream>

template<typename T, typename U>
class DogTemplate {
  public:
    T attr1;
    U attr2;
};


// 非法
// template<typename T>
// typedef DogTemplate<std::vector<T>, std::string> DogT;

// 合法
template<typename T>
using DogT = DogTemplate<std::vector<T>, std::string>;

int main() {
  return 0;
}