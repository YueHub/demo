int (* func1(int arr[][3], int n))[3] {
  return &arr[n];
}

auto func1(int arr[][3], int n) -> int(*)[3] {
  return &arr[n];
}

int main() {
  return 0;
}