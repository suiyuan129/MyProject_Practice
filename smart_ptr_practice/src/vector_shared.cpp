#include<iostream>
#include<vector>
#include<memory>

int main(){
    std::vector<std::shared_ptr<int>> vec;
    auto p=std::make_shared<int>(100);
    vec.push_back(p);
    vec.push_back(p);
    std::cout<<"引用计数："<<p.use_count()<<std::endl;
    return 0;
}