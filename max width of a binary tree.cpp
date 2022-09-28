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
    int widthOfBinaryTree(TreeNode* root) {
        
        unordered_map<TreeNode*,int> map;
        
        queue<TreeNode*> queue;
        queue.push(root);
        map[root] = 0;
        
        int max_width = INT_MIN;
        
        while(!queue.empty()){
            int n = queue.size();
            long i,min_i = INT_MAX;
            int left = INT_MAX, right = INT_MIN;
            for(int k=0;k<n;k++){
                TreeNode* temp = queue.front();
                queue.pop();
                left = min(left,map[temp]);
                right = max(right,map[temp]);
                i = map[temp];
                cout<<i<<" ";
                min_i = min(i*2+1,min_i);
                if(temp->left){
                    queue.push(temp->left);
                    map[temp->left] = i*2+1 - min_i;
                }
                if(temp->right){
                    queue.push(temp->right);
                    map[temp->right] = i*2+2 - min_i;
                }
            }
            
            max_width = max(max_width,right - left + 1);
        }
        
        return max_width;
    }
};
