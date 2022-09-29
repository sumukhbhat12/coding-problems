/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        int pleft = 0, pright = preorder.size()-1, ileft = 0, iright = inorder.size()-1;
        return createBT(preorder,inorder,pleft,pright,ileft,iright,map);
    }
    
    TreeNode* createBT(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft, int iright, unordered_map<int,int> &map){
        if(pleft > pright || ileft > iright){
            return NULL;
        }
        int i = map[preorder[pleft]];
        TreeNode* root = new TreeNode(preorder[pleft]);
        int n_inorder_left = i-ileft;
        int n_inorder_right = iright - i;
        
        root->left = createBT(preorder,inorder,pleft+1,pleft+n_inorder_left,ileft,i-1,map);
        root->right = createBT(preorder,inorder,pleft+n_inorder_left+1,pright,i+1,i+n_inorder_right,map);
        
        return root;
        
    }
};
