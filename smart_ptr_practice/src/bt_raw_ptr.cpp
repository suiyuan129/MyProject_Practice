#include<iostream>
#include<memory>

struct TreeNode
{
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    TreeNode(int _val):val(_val){}
};

void preorder(const std::shared_ptr<TreeNode>& root){
    if(!root) return;
    std::cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    auto root=std::make_shared<TreeNode>(1);
    root->left=std::make_shared<TreeNode>(2);
    root->right=std::make_shared<TreeNode>(3);
    preorder(root);
    return 0;
}