#include<iostream>
#include<vector>

int sum_vector(const std::vector<int>& nums){
    int total=0;
    for(int num:nums){
        total+=num;
    }
    return total;
}

int main(){
    int a=10;
    int b=20;
    std::cout<<"初始值：a="<<a<<",b="<<b<<std::endl;

    a+=5;
    b*=2;
    std::cout<<"修改后：a="<<a<<",b="<<b<<std::endl;

    std::vector<int> nums={1,2,3,4};
    int total=sum_vector(nums);
    std::cout<<"数组总和："<<total<<std::endl;

    return 0;
}