#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int main() {
  const int THREAD_NUM = 4;
  const int TASK_NUM = 10000;
  int shared_counter = 0;
  std::mutex mtx;
  std::vector<std::thread> threads;

  auto thread_task = [&]() {
    for (int i = 0; i < TASK_NUM; ++i) {
      std::lock_guard<std::mutex> lock(mtx);
      shared_counter++;
    }
  };

  for (int i = 0; i < THREAD_NUM; ++i) {
    threads.emplace_back(thread_task);
  }

  for (auto& t : threads) {
    t.join();
  }

  std::cout << "共享计数器最终值: " << shared_counter << std::endl;
  return 0;
}