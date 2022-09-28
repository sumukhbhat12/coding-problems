class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int temp = findPathSum(root,maxSum);
        return maxSum;
    }
    
    int findPathSum(TreeNode* root, int &maxSum){
        if(!root){
            return 0;
        }
        
        int leftSum = findPathSum(root->left,maxSum);
        int rightSum = findPathSum(root->right,maxSum);


        maxSum = max(maxSum,leftSum + rightSum + root->val);
        maxSum = max(maxSum,leftSum + root->val);
        maxSum = max(maxSum,rightSum + root->val);
        maxSum = max(maxSum,root->val);

        int sum = max(leftSum,rightSum);
        sum = max(root->val,sum + root->val);
        
        return sum;
        
    }
};
