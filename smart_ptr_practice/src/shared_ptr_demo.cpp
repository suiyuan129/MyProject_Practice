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
private:
    int _id;
};

int main(){
    std::shared_ptr<Test> ptr1(new Test(2));
    std::cout<<"ptr1 引用计数："<<ptr1.use_count()<<std::endl;

    std::shared_ptr<Test> ptr2=ptr1;
    std::cout<<"ptr1 引用计数："<<ptr1.use_count()<<std::endl;
    std::cout<<"ptr2 引用计数："<<ptr2.use_count()<<std::endl;

    {
        std::shared_ptr<Test> ptr3=ptr2;
        std::cout<<"ptr3 引用计数："<<ptr3.use_count()<<std::endl;
    }

    std::cout<<"ptr1 引用计数（ptr3销毁后）："<<ptr1.use_count()<<std::endl;

    return 0;
}