class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<int> temp1, temp2;
        
        //either you can choose 0 to n-2 from the nums array
        //or you can choose1 to n-1 from the nums array
        //since the first and the last elements are always the neighbours
        
        for(int i=0;i<nums.size();i++){
            if(i != 0){
                temp1.push_back(nums[i]);
            }
            if(i != nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        vector<int> dp1(temp1.size(),-1), dp2(temp2.size(),-1);
        //select the maximum from both the arrays
        return max(helper(temp1.size()-1,temp1,dp1), helper(temp2.size()-1,temp2,dp2));
    }
    
    
    
    int helper(int n, vector<int> &nums, vector<int> &dp){
        
            if(n == 0){
                return nums[0];
            }
            int pick = INT_MIN, notpick = INT_MIN;
            if(dp[n] != -1)
                return dp[n];
            
            pick = nums[n];
            if(n-2>=0){
                pick += helper(n-2,nums,dp);
            }
            notpick = helper(n-1,nums,dp);
            return dp[n] = max(pick,notpick);
        }
       
        
        
    
};
