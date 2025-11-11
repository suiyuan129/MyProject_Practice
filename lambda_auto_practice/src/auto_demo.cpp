#include<iostream>
#include<vector>
#include<map>

int main(){
    auto a=10;
    auto b=3.14;
    auto c="hello";
    std::cout<<"a="<<a<<"（类型：int）\n";
    std::cout<<"b="<<b<<"（类型：double）\n";
    std::cout << "c=" << c << "（类型：const char*）\n";

    std::vector<int> nums={1,2,3,4};
    auto it=nums.begin();
    for(;it!=nums.end();++it){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    std::map<std::string,int> score={{"Alice",90},{"Bob",85}};
    auto p=*score.begin();
    std::cout<<"姓名："<<p.first<<"分数："<<p.second<<"\n";

    int arr[5]={1,2,3,4,5};
    auto arr1=arr;
    std::cout<<"arr是数组（地址："<<arr<<"），arr1是指针（地址："<<arr1<<"）\n";

    return 0;
}