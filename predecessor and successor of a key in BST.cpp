#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    pair<int,int> ans = {-1,-1};
    BinaryTreeNode<int> *cur = root;
    while(cur){
        if(cur->data == key){
            break;
        }
        else
        if(cur->data > key){
            ans.second = cur->data;
            cur = cur->left;
        }
        else{
            ans.first = cur->data;
            cur = cur->right;
        }
    }
    if(!cur){
        ans = {-1,-1};
        return ans;
    }
    BinaryTreeNode<int> *next = cur->left;
    while(next && next->right){
        next = next->right;
    }
    if(next){
        ans.first = next->data;
    }
    next = cur->right;
    while(next && next->left){
        next = next->left;
    }
    if(next){
        ans.second = next->data;
    }
    
    return ans;
}
