#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  auto print_hello = []() { std::cout << "Hello lambda!\n"; };
  print_hello();

  auto add = [](int a, int b) { return a + b; };
  std::cout << "3+5=" << add(3, 5) << "\n";

  auto divide = [](double a, double b) -> double {
    if (b == 0) return 0;
    return a / b;
  };
  std::cout << "10/3=" << divide(10, 3) << "\n";

  int x = 10, y = 20;
  auto func1 = [x, y]() {
    std::cout << "值捕获：x=" << x << ",y=" << y << "\n";
  };
  func1();

  auto func2 = [&x, &y]() {
    x = 100;
    y = 200;
    std::cout << "引用部分：x=" << x << ",y=" << y << "\n";
  };
  func2();
  std::cout << "外部 x=" << x << ",y=" << y << "\n";

  auto func3 = [x, &y]() {
    y = 500;
    std::cout << "混合捕获：x=" << x << ",y=" << y << "\n";
  };
  func3();

  std::vector<int> nums = {3, 1, 4, 1, 5, 9};
  std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
  std::cout << "降序排列后：";
  for (auto num : nums) std::cout << num << " ";
  std::cout << "\n";

  return 0;
}