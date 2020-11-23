class noncopyable { 
public: 
  noncopyable() = default;
  noncopyable(const noncopyable&) = delete;
  noncopyable& operator=(const noncopyable&) = delete;
};

int main() {
  noncopyable copy;

  return 0;
}