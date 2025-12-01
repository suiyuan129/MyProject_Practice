#include<iostream>
#include<memory>
#include<cstdio>

int main(){
    FILE* file=fopen("text.txt","w");
    if(!file) return 1;
    std::shared_ptr<FILE> fileptr(file,[](FILE* f){
        fclose(f);
        std::cout<<"文件已关闭"<<std::endl;
    });
    fprintf(fileptr.get(),"Hello,Smart Pointer!");
    return 0;
}