class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //for space optimization, i.e 3rd appraoch, this is not needed
        //vector<vector<int>> dp(n,vector<int>(amount+1,0));
        int ans = helper3(n-1,amount,coins);
        if(ans >= 1e9)
            return -1;
        else
            return ans;
    }
    
    //TOPDOWN APPRAOCH
    int helper(int n, int amount, vector<int>& coins, vector<vector<int>> &dp){
        
        if(amount == 0){
            return 0;
        }
        
        if(n == 0){
            if(coins[n] <= amount)
                return 1 + helper(n,amount-coins[n],coins,dp);
            else
                return 1e9;
        }
        
        if(dp[n][amount] != -1)
            return dp[n][amount];
        
        int pick = 1e9, notpick = 1e9;
        notpick = helper(n-1,amount,coins,dp);
        
        if(coins[n] <= amount)
            pick = 1 + helper(n,amount-coins[n],coins,dp);
        
        
        return dp[n][amount] = min(pick,notpick);
    }
    
    //BOTTOM UP APPROACH
    int helper2(int n, int amount, vector<int>& coins, vector<vector<int>> &dp){
        
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=amount;i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
            
            
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int pick = 1e9, notpick = 1e9;
                notpick = dp[i-1][j];
                if(coins[i] <= j)
                    pick = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(pick,notpick);
            }
        }
        
        return dp[n][amount];
    }
    
    //SPACE OPTIMIZATION O(M) where M - sizeof amount
    int helper3(int n, int amount, vector<int>& coins){
        
        vector<int> prev(amount+1,0), cur(amount+1,0);
        
        
        prev[0] = 0;
        cur[0] = 0;
        
        for(int i=1;i<=amount;i++){
            if(i % coins[0] == 0){
                prev[i] = i / coins[0];
            }
            else{
                prev[i] = 1e9;
            }
            
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int pick = 1e9, notpick = 1e9;
                notpick = prev[j];
                if(coins[i] <= j)
                    pick = 1 + cur[j-coins[i]];
                cur[j] = min(pick,notpick);
            }
            prev = cur;
        }
        
        return prev[amount];
    }
};
