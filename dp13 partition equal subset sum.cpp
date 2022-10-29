class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(auto i : nums){
            sum += i;
        }
        if(sum & 1){
            return false;
        }
        else{
            vector<vector<int>> dp(n,vector<int>(sum/2 + 1, 0));
            return helper2(n-1,sum/2,nums,dp);
        }
    }
    
    //TOP DOWN APPROACH
    int helper(int n, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(n == 0){
            return nums[n] == target;
        }
        if(target == 0){
            return 1;
        }
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        int pick = 0, notpick = 0;
        notpick = helper(n-1,target,nums,dp);
        if(nums[n] <= target)
            pick = helper(n-1,target-nums[n],nums,dp);
        
        return dp[n][target] = pick or notpick;
    }
    
    //BOTTOM UP APPROACH
    int helper2(int n, int target, vector<int>& nums, vector<vector<int>> &dp){
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        if(nums[0] <= target)
            dp[0][nums[0]] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                int pick = 0, notpick = 0;
                notpick = dp[i-1][j];
                if(nums[i] <= j){
                    pick = dp[i-1][j-nums[i]];
                }
                
                dp[i][j] = pick or notpick;
            }
        }
        
        return dp[n][target];
    }
};
