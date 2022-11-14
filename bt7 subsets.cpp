class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        
        helper(n-1,nums,temp,ans);
        
        return ans;
    }
    
    void helper(int n, vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans){
        
        //no need for base case because the for loop checks automatically
        ans.push_back(temp);
        
        for(int i=n;i>=0;i--){
            temp.push_back(nums[i]);
            helper(i-1,nums,temp,ans);
            temp.pop_back();
        }
        
        
    }
    
};
