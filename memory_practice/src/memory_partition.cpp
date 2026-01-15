#include <iostream>
using namespace std;

int global_val = 10;
int global_val_0 = 0;
int global_val_uninit;

int main() {
  int stack_val = 20;
  const char* rodata_str = "hello memory";
  cout << "全局区（data）global_val地址：" << &global_val << endl;
  cout << "全局区（bss）global_val_0地址：" << &global_val_0 << endl;
  cout << "全局区（bss）global_val_uninit地址：" << &global_val_uninit << endl;
  cout << "栈区stack_val地址：" << &stack_val << endl;
  cout << "常量区rodata_str地址：" << (void*)rodata_str << endl;
  cout << "代码区main函数地址：" << (void*)main << endl;
  return 0;
}