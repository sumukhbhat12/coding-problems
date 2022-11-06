class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        //return helper2(0,-1,nums,dp);
        return helper3(0,-1,nums);
    }
    
    //TOPDOWN APPROACH
    int helper(int n, int p, vector<int> &nums, vector<vector<int>> &dp){
        if(n == nums.size()){
            return 0;
        }
        
        if(dp[n][p+1] != -1){
            return dp[n][p+1];
        }
        
        int pick = 0, notpick = 0;
        
        notpick = helper(n+1,p,nums,dp);
        if(p == -1 || nums[n] > nums[p]){
            pick = 1 + helper(n+1,n,nums,dp);
        }
        
        return dp[n][p+1] = max(pick, notpick);
    }
    
    //BOTTOMUP APPROACH
    int helper2(int n, int p, vector<int> &nums, vector<vector<int>> &dp){
        int m = nums.size();
        
        //base case. initialize the last row with 0s, done by default
        
        for(int i=m-1;i>=0;i--){
            for(int j=m-1;j>=-1;j--){
                int pick = 0, notpick = 0;
                notpick = dp[i+1][j+1];
                if(j == -1 || nums[i] > nums[j]){
                    pick = 1 + dp[i+1][i+1];    //dp[i+1][i+1] --> i+1 because we have offset the j's parameter from -1 to 0
                }
                dp[i][j+1] = max(pick,notpick);
            }
        }
        
        return dp[n][p+1];
    }
    
    //SPACE OPTIMIZATION APPROACH O(N)
    int helper3(int n, int p, vector<int> &nums){
        int m = nums.size();
        
        vector<int> next(m+1,0);//, cur(m+1,0);
        //base case. initialize the last row with 0s, done by default
        
        for(int i=m-1;i>=0;i--){
            for(int j=m-1;j>=-1;j--){
                int pick = 0, notpick = 0;
                notpick = next[j+1];
                if(j == -1 || nums[i] > nums[j]){
                    pick = 1 + next[i+1];    //dp[i+1][i+1] --> i+1 because we have offset the j's parameter from -1 to 0
                }
                next[j+1] = max(pick,notpick);
            }
            //next = cur;
        }
        
        return next[p+1];
    }
    
};
