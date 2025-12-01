#include<iostream>
#include<memory>

void myDeleter(int* p){
    std::cout<<"自定义删除器：释放int指针 "<<p<<std::endl;
    delete p;
}

int main(){
    std::shared_ptr<int> p1(new int(10),myDeleter);
    std::unique_ptr<int,decltype(&myDeleter)> p3(new int(20),myDeleter);
    return 0;
}