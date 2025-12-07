#include<iostream>
#include<memory>

int main(){
    std::unique_ptr<int> up(new int(50));
    std::shared_ptr<int> sp=std::move(up);
    if(!up) std::cout<<"up已失去所有权"<<std::endl;
    std::cout<<"sp的值"<<*sp<<std::endl;
    std::weak_ptr<int> wp=sp;
    if(auto temp=wp.lock()){
        std::cout<<"wp转换为sp,值: "<<*temp<<std::endl;
    }
    return 0;
}