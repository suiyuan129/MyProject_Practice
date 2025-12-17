#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
  int id;
  int score;
  std::string name;
};

int main() {
  std::vector<Student> students = {{101, 85, "Bob"},
                                   {102, 92, "Alice"},
                                   {103, 85, "Charlie"},
                                   {104, 95, "David"}};
  std::sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) {
              if (a.score != b.score)
                return a.score > b.score;
              else
                return a.name < b.name;
            });
  auto high_score_it = std::find_if(
      students.begin(), students.end(),
      [](const Student& s) { return s.score >= 90 && s.name.size() >= 5; });
  if (high_score_it != students.end()) {
    std::cout << "目标学生：id=" << high_score_it->id
              << ",name=" << high_score_it->name << std::endl;
  };
  int mid_count = std::count_if(
      students.begin(), students.end(),
      [](const Student& s) { return s.score >= 80 && s.score <= 90; });
  std::cout << "80-90分学生数量: " << mid_count << std::endl;
  std::for_each(students.begin(), students.end(), [](const Student& s) {
    std::cout << "学生id: " << s.id << " 学生姓名： " << s.name
              << " 学生分数: " << s.score << std::endl;
  });
  return 0;
}