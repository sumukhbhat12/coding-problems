#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(!root)
        return;
    if(root->left == NULL && root->right == NULL){
        return;
    }
    int rootVal = root->data, lval = 0, rval = 0;
    if(root->left)
        lval = root->left->data;
    if(root->right)
        rval = root->right->data;
    
    if(rootVal < lval + rval){
        root->data = lval + rval;
    }
    rootVal = root->data;
    if(root->left)
        root->left->data = rootVal;
    if(root->right)
        root->right->data = rootVal;
    
    changeTree(root->left);
    changeTree(root->right);
    
    if(root->left)
        lval = root->left->data;
    if(root->right)
        rval = root->right->data;
    
    root->data = lval + rval;
    
}  
