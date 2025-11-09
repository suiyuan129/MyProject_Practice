#include<iostream>
#include<memory>

class B;

class A{
public:
    std::shared_ptr<B> b_ptr;
    ~A(){
        std::cout<<"A 析构"<<std::endl;
    }
};

class B{
public:
    std::weak_ptr<A> a_ptr;
    ~B(){
        std::cout<<"B 析构"<<std::endl;
    }
};

int main(){
    {
    std::shared_ptr<A> a(new A());
    std::shared_ptr<B> b(new B());
    a->b_ptr=b;
    b->a_ptr=a;
    }
    std::cout<<"main函数结束"<<std::endl;
    return 0;
}