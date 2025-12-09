#include<iostream>
#include<memory>
#include<string>

int main(){
    int a=10;
    double b=3.14;
    auto ptr=std::make_unique<int>(20);
    std::string str="Lambda";
    auto lambda1=[=](){
        std::cout<<"全值捕获：a="<<a<<"，b="<<b<<",str="<<str<<std::endl;
    };
    auto lambda2=[=]() mutable{
        ++a;
        b*=2;
        std::cout<<"mutable全值捕获：a="<<a<<"，b="<<b<<std::endl;
    };
    auto lambda3=[=,&a](){
        ++a;
        std::cout<<"混合捕获：原a="<<a<<"，拷贝b="<<b<<std::endl;
    };
    auto lambda4=[ptr=std::move(ptr),str](){
        std::cout<<"移动捕获ptr："<<*ptr<<"，拷贝str："<<str<<std::endl;
    };
    lambda1();
    lambda2();
    lambda3();
    lambda4();
    std::cout<<"执行后原变量：a="<<a<<"，b="<<b<<std::endl;
    return 0;
}