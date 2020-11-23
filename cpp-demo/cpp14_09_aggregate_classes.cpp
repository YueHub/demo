struct CXX14_aggregate {
  int x;
  int y = 42;
};

CXX14_aggregate a = { 1 }; // C++14允许。 a.y 被初始化为42

int main() {
  return 0;
}