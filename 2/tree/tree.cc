#include "tree.h"



Tree::Tree(): root{nullptr} {}
Tree::~Tree() { delete root; }

void Tree::insert (int data) {
    if (!root) {
        root = new TreeNode(data, TreeNode::Kind::Root, nullptr);
        return;
    }
    TreeNode *cur = root;
    while (true) {
        if (cur->data == data) return;
        if (cur->data < data) {
            if (!cur->right) {
                cur->right = new TreeNode(data, TreeNode::Kind::Right, cur);
                return;
            }
            else {
                cur = cur->right;
            }
        }
        else if (cur->data > data) {
            if (!cur->left) {
                cur->left = new TreeNode(data, TreeNode::Kind::Left, cur);
                return;
            }
            else {
                cur = cur->left;
            }
        }
    }
}



Tree::Iterator Tree::begin(){
    TreeNode *mostLeft = root;
    if (root==nullptr){
        return Iterator(nullptr,nullptr);
    }
    while (mostLeft->left!=nullptr){
        mostLeft = mostLeft->left;
    }
    return Iterator(mostLeft,root);
}

Tree::Iterator Tree::end(){
    /*TreeNode *mostRight = root;
    if (root==nullptr){
        return Iterator(nullptr);
    }
    while (mostRight->right!=nullptr){
        mostRight = mostRight->right;
    }
    return Iterator(mostRight);*/
    return Iterator(nullptr,root);
}













