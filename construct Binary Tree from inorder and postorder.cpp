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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        int ileft = 0, iright = inorder.size()-1, pleft = 0, pright = postorder.size()-1;
        return createBT(inorder,postorder,ileft,iright,pleft,pright,map);
    }
    
    TreeNode* createBT(vector<int>& inorder, vector<int>& postorder, int ileft, int iright, int pleft, int pright, unordered_map<int,int> &map){
        if(ileft < 0 || iright < 0 || pleft < 0 || pright < 0 || ileft > iright || pleft > pright){
            return NULL;
        }
        
        int i = map[postorder[pright]];
        TreeNode* root = new TreeNode(postorder[pright]);
        int left_nodes = i - ileft;
        int right_nodes = iright - i;
        
        root->left = createBT(inorder,postorder,ileft,ileft+left_nodes-1,pleft,pleft+left_nodes-1,map);
        root->right = createBT(inorder,postorder,i+1,i+right_nodes,pleft+left_nodes,pright-1,map);
        
        return root;
    }
};
