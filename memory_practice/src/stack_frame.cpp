#include <iostream>
using namespace std;

// 测试函数：观察参数、局部变量在栈中的存储
void test_stack(int a, int b) {
    int c = a + b;
    int d = a * b;
    // 打印参数和局部变量地址，观察栈生长方向（地址从大到小）
    cout << "test_stack函数栈帧：" << endl;
    cout << "参数b地址：" << &b << "  值：" << b << endl;
    cout << "参数a地址：" << &a << "  值：" << a << endl;
    cout << "局部变量c地址：" << &c << "  值：" << c << endl;
    cout << "局部变量d地址：" << &d << "  值：" << d << endl;
}

int main() {
    int x = 10, y = 20;
    cout << "main函数中x地址：" << &x << "  y地址：" << &y << endl;
    test_stack(x, y);
    return 0;
}