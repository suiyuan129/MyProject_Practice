#include<iostream>
#include<vector>
#include<memory>

int main(){
    std::vector<std::unique_ptr<int>> vec;
    vec.emplace_back(std::make_unique<int>(1));
    vec.emplace_back(std::make_unique<int>(2));
    vec.emplace_back(std::make_unique<int>(3));
    for(const auto& ptr:vec){
        std::cout<<*ptr<<" ";
    }
    std::cout<<std::endl;
    auto p=std::move(vec[0]);
    std::cout<<"取出元素："<<*p<<std::endl;
    std::cout<<"vec[0]是否为空："<<(vec[0]?"是":"否")<<std::endl;
    return 0;
}