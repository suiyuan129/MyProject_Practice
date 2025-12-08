#include<iostream>
#include<memory>

int main(){
    std::shared_ptr<int> arr1(new int[5],std::default_delete<int[]>());
    std::shared_ptr<int> arr2(new int[5],[](int* p){
        delete[] p;
    });
    return 0;
}