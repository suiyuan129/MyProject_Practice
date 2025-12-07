#include <iostream>
#include <memory>

class LogDeleter {
 private:
  bool Log;

 public:
  LogDeleter(bool _Log) : Log(_Log) {}
  void operator()(int* p) {
    if (Log) {
      std::cout << "[日志开启：使用LogDeleter]释放int指针 " << p << std::endl;
      delete p;
    } else {
      std::cout << "[日志关闭：使用LogDeleter]释放int指针" << p << std::endl;
      delete p;
    }
  }
};

int main() {
  std::shared_ptr<int> p1(new int(30), LogDeleter(true));
  std::unique_ptr<int, LogDeleter> p2(new int(40), LogDeleter(false));
  std::cout << p1 << " " << *p1 << std::endl;
  std::cout << p2.get() << " " << *p2 << std::endl;
  return 0;
}