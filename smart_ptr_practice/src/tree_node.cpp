#include<iostream>
#include<memory>

class TreeNode{
public:
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    std::weak_ptr<TreeNode> parent;

    TreeNode(int v):val(v){
        std::cout<<"TreeNode "<<val<<" 构造"<<std::endl;
    }
    ~TreeNode(){
        std::cout<<"TreeNode "<<val<<" 析构"<<std::endl;
    }
};

int main(){
    auto root=std::make_shared<TreeNode>(1);
    auto leftChild=std::make_shared<TreeNode>(2);
    leftChild->parent=root;
    root->left=leftChild;
    if(auto parent=leftChild->parent.lock()){
        std::cout<<"子节点2的父节点值："<<parent->val<<std::endl;
    }
    return 0;
}