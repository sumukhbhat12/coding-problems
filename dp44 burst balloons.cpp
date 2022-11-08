class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // 1 3 1 5 8 1
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        return helper2(1,nums.size()-2,nums,dp);
    }
    
    //TOPDOWN APPROACH
    int helper(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int coins;
        int maxi = INT_MIN;
        for(int k = i;k<=j;k++){
            
            coins = nums[i-1] * nums[k] * nums[j+1] + helper(i,k-1,nums,dp) + helper(k+1,j,nums,dp);
            maxi = max(maxi,coins);
        }
        
        return dp[i][j] = maxi;
    }
    
    
    //BOTTOMUP APPROACH
    int helper2(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        
        int n = nums.size();
        
        for(int i=n-2;i>=1;i--){
            for(int j=1;j<=n-2;j++){
                
                if(i > j)
                    continue;
                
                int coins;
                int maxi = INT_MIN;
                for(int k = i;k<=j;k++){

                    coins = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,coins);
                }

                dp[i][j] = maxi;
            }
        }
        
        return dp[i][j];
    }
    
};
