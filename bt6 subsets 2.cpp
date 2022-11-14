class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        helper(n-1,nums,temp,ans);
        return ans;
    }
    
    void helper(int n, vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans){
        if(n < 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=n;i>=0;i--){
            if(i != n && nums[i] == nums[i+1]){
                continue;
            }
                temp.push_back(nums[i]);
                helper(i-1,nums,temp,ans);
                temp.pop_back();
        }
        
        ans.push_back(temp);
    }
    
};
