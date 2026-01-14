#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
  std::mutex mtx;
  std::condition_variable cv;
  bool data_ready = false;
  int data = 0;

  std::thread consumer([&]() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&data_ready] { return data_ready; });
    std::cout << "消费者：收到数据=" << data << std::endl;
  });

  std::thread producer([&]() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
      std::lock_guard<std::mutex> lock(mtx);
      data = 100;
      data_ready = true;
      std::cout << "生产者：数据生成完成" << std::endl;
    }
    cv.notify_one();
  });
  consumer.join();
  producer.join();
  return 0;
}