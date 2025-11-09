#include<iostream>
#include<memory>

class Test{
public:
    Test(int id):_id(id){
        std::cout<<"Test"<<_id<<"构造"<<std::endl;
    }
    ~Test(){
        std::cout<<"Test"<<_id<<"析构（内存释放）"<<std::endl;
    }
    void print(){
        std::cout<<"Test"<<_id<<"执行"<<std::endl;
    }
private:
    int _id;
};

int main(){
    std::unique_ptr<Test> ptr1(new Test(1));
    ptr1->print();
    //std::unique_ptr<Test> ptr2=ptr1;
    std::unique_ptr<Test> ptr2=std::move(ptr1);
    if(ptr1==nullptr){
        std::cout<<"ptr1已失去所有权"<<std::endl;
    }
    ptr2->print();

    return 0;
}