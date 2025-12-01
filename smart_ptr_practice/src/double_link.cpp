#include<iostream>
#include<memory>

class Node{
public:
    std::weak_ptr<Node> prev;
    std::shared_ptr<Node> next;
    int val;
    Node(int v):val(v){}
    ~Node(){
        std::cout<<"Node "<<val<<" 析构"<<std::endl;
    }
};

int main(){
    auto n1=std::make_shared<Node>(1);
    auto n2=std::make_shared<Node>(2);
    n1->next=n2;
    n2->prev=n1;
    return 0;
}