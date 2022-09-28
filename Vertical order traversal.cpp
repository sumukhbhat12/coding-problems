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
class Complex{
    public:
    int h_dist;
    int level;
    TreeNode* node;
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<Complex> nodes;
        vector<vector<int>> ans;
        vector<int> temp;
        preorderTraverse(root,0,0,nodes);
        
        
        sort(nodes.begin(),nodes.end(),[](const Complex &a, const Complex &b){
            if(a.h_dist < b.h_dist) return true;
            if(a.h_dist > b.h_dist) return false;
            //if horizontal distance is same, sort by level
            if(a.level < b.level) return true;
            if(a.level > b.level) return false;
            //if horizontal distance and level is same, sort by values
            if(a.node->val < b.node->val) return true;
            if(a.node->val > b.node->val) return false;
            return false;
        });
        
        
        temp.push_back(nodes[0].node->val);
        int i=1;
        int j=nodes[0].h_dist;
        int n = nodes.size();
        while(i<n){
            while(i<n && nodes[i].h_dist == j){
                temp.push_back(nodes[i].node->val);
                i++;
            }
            if(i < n){
                j = nodes[i].h_dist;
            }
            
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
        
    }
    
    void preorderTraverse(TreeNode* root, int h_dist, int level, vector<Complex> &nodes){
        if(root){
            Complex temp;
            temp.h_dist = h_dist;
            temp.level = level;
            temp.node = root;
            nodes.push_back(temp);
            
            preorderTraverse(root->left,h_dist-1,level+1,nodes);
            preorderTraverse(root->right,h_dist+1,level+1,nodes);
        }
    }
};
.
