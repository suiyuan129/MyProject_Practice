#include<iostream>
#include<memory>
#include<sys/socket.h>
#include<unistd.h>

int main(){
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        perror("socket创建失败");
        return 1;
    }
    std::shared_ptr<int> sockPtr(&sockfd,[](int* fd){
        close(*fd);
        std::cout<<"Socket "<<*fd<<" 已关闭"<<std::endl;
    });
    std::cout<<"Socket创建成功,fd="<<sockfd<<std::endl;
    std::cout<<*sockPtr<<std::endl;
    return 0;
}