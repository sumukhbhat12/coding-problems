#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/


class Node{
    public:
    Node(){
        max = INT_MIN;
        min = INT_MAX;
        size = 0;
        node = NULL;
    }
      int max;
      int min;
      int size;
      TreeNode<int> *node;
};
Node* postorderTraverse(TreeNode<int>* root);
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    Node* temp = postorderTraverse(root);
    return temp->size;
}
Node* postorderTraverse(TreeNode<int>* root){
    if(root){
        Node* left = new Node(), *right = new Node() , *temp = new Node();
        if(!root->left && !root->right){
            temp->max = root->data;
            temp->min = root->data;
            temp->size = 1;
            temp->node = root;
            return temp;
        }
        
        if(root->left)
            left = postorderTraverse(root->left);
        if(root->right)
            right = postorderTraverse(root->right);
        
        
        temp->node = root;
        if(left->max < root->data && right->min > root->data){
            temp->max = right->max != INT_MIN ? right->max : right->min != INT_MAX ? right->min : temp->node->data;
            temp->min = left->min != INT_MAX ? left->min : left->max != INT_MIN ? left->max : temp->node->data;
            temp->size = 1 + left->size + right->size;
        }
        else{
            //make this tree not calculable any further, upwards the tree
            temp->max = INT_MAX;
            temp->min = INT_MIN;
            temp->size = max(left->size,right->size);
        }
        return temp;
    }
    return new Node();
}
