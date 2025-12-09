#include<iostream>
#include<functional>
#include<chrono>
#include<thread>

std::function<void()> bad_callback(){
    int local_val=100;
    return [&local_val](){std::cout<<"错误：悬垂引用val="<<local_val<<std::endl;};
}

std::function<void()> good_callback1(){
    int local_val=100;
    return [local_val](){std::cout<<"正确：值捕获val="<<local_val<<std::endl;};
}

std::function<void()> good_callback2(){
    std::string local_str="Safe Lambda";
    return [str=std::move(local_str)](){std::cout<<"正确2：移动捕获str="<<str<<std::endl;};
}

int main(){
    auto bad=bad_callback();
    auto good1=good_callback1();
    auto good2=good_callback2();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    bad();
    good1();
    good2();
    return 0;
}