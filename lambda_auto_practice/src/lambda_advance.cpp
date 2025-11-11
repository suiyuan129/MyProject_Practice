#include<iostream>
#include<vector>
#include<functional>

void test_capture_mode(){
    int a=1,b=2;
    auto func1=[=](){
        std::cout<<"a="<<a<<",b="<<b<<"\n";
    };
    func1();

    auto func2=[&](){
        a=10,b=20;
        std::cout<<"修改后：a="<<a<<",b="<<b<<"\n";
    };
    func2();
}

void test_mutable(){
    int x=5;
    auto func=[x]()mutable{
        x=10;
        std::cout<<"lambda内x="<<x<<"\n";
    };
    func();
    std::cout<<"外部x="<<x<<"\n";
}

std::function<int(int,int)> get_calculator(char op){
    if(op=='+') return [](int a,int b){return a+b;};
    else if(op=='-') return [](int a,int b){return a-b;};
    else return [](int a,int b){return 0;};
}

void test_stl(){
    std::vector<int> nums={1,2,3,4,5};
    int sum=0;

    std::for_each(nums.begin(),nums.end(),[&sum](int num){
        sum+=num;
    });

    std::cout<<"数组总和："<<sum<<"\n";
}

int main(){
    std::cout<<"===捕获模式测试===\n";
    test_capture_mode();

    std::cout<<"\n===mutable测试===\n";
    test_mutable();

    std::cout<<"\n===lambda作为返回值测试===\n";
    auto add=get_calculator('+');
    auto sub=get_calculator('-');
    std::cout<<"10+5="<<add(10,5)<<"\n";
    std::cout<<"10-5="<<sub(10,5)<<"\n";

    std::cout<<"\n===STL结合lambda===\n";
    test_stl();

    return 0;
}