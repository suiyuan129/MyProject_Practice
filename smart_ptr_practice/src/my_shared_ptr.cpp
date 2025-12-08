#include <atomic>
#include <iostream>

template <typename T>
class MySharedPtr {
 private:
  T* ptr;
  std::atomic<int>* ref_cnt;
  void release() {
    if (ref_cnt && --(*ref_cnt) == 0) {
      delete ptr;
      delete ref_cnt;
      std::cout << "资源已释放" << std::endl;
    }
  }

 public:
  explicit MySharedPtr(T* p = nullptr)
      : ptr(p), ref_cnt(new std::atomic<int>(1)) {
    std::cout << "MySharedPtr构造，引用计数初始化为1" << std::endl;
  }
  MySharedPtr(const MySharedPtr& other)
      : ptr(other.ptr), ref_cnt(other.ref_cnt) {
    ++(*ref_cnt);
    std::cout << "MySharedPtr拷贝构造，引用计数变为" << *ref_cnt << std::endl;
  }
  ~MySharedPtr() {
    std::cout << "MySharedPtr析构，引用计数减1" << std::endl;
    release();
  }
  T& operator*() const { return *ptr; }
  T* operator->() const { return ptr; }
  int use_count() const { return *ref_cnt; }
};

int main() {
  MySharedPtr<int> p1(new int(10));
  std::cout << "p1引用计数：" << p1.use_count() << std::endl;

  MySharedPtr<int> p2 = p1;
  std::cout << "p2拷贝后，p1引用计数：" << p1.use_count() << std::endl;

  return 0;
}