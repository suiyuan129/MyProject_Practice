#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

int main(){
    std::vector<int> nums={1,2,3,4,5,6,7,8,9};
    std::vector<int> res;

    std::transform(nums.begin(),nums.end(),std::back_inserter(res),[](int x){
        return x*x;
    });
    std::replace_if(res.begin(),res.end(),[](int x){
        return x%2==0;
    },0);
    int sum=0;
    std::for_each(res.begin(),res.end(),[&sum](int x){
        if(x!=0)sum+=x;
    });
    std::cout<<"转换替换后数组: ";
    for(int x:res) std::cout<<x<<" ";
    std::cout<<"\n非0数组总和: "<<sum<<std::endl;
    return 0;
}