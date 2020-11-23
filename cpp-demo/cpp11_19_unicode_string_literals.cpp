#include <iostream>

using namespace std;

int main() {
  string path1 = "D:\\work\\book\\read_proj";
  string path2 = R"(D:\work\book\read_proj)";
  string path3 = R"(D:\work\book\read_proj)";
  // - 作为分隔符，以便正确标示开始与结尾（应该尽量选择原始字符串中没有的字符）
  string path4 = R"-(a\b\c)"\daaa\e)-"; 

  cout << path1 << endl;
  cout << path2 << endl;
  cout << path3 << endl;
  cout << path4 << endl;
  return 0;
}