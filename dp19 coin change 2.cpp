class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //vector<vector<int>> dp(n,vector<int>(amount+1,0));
        return helper3(n-1,amount,coins);
    }
    
    //TOPDOWN APPROACH
    int helper(int n, int amount, vector<int>& coins, vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }
        
        if(n == 0){
            if(amount % coins[n] == 0){
                return 1;
            }
            else
                return 0;
        }
        if(dp[n][amount] != -1)
            return dp[n][amount];
        int pick = 0, notpick = 0;
        notpick = helper(n-1,amount,coins,dp);
        if(coins[n] <= amount){
            pick = helper(n,amount - coins[n],coins,dp);
        }
        
        return dp[n][amount] = pick + notpick;
    }
    
    //BOTTOM UP APPRAOCH
    int helper2(int n, int amount, vector<int>& coins, vector<vector<int>> &dp){
        dp[0][0] = 1;
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=amount;i++){
            if(i % coins[0] == 0)
                dp[0][i] = 1;
            else
                dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                int pick = 0, notpick = 0;
                notpick = dp[i-1][j];
                if(coins[i] <= j){
                    pick = dp[i][j - coins[i]];
                }
                dp[i][j] = pick + notpick;
            }
        }
        
        
        return dp[n][amount];
        
    }
    
    //SPACE OPTIMIZATION O(AMOUNT)
    int helper3(int n, int amount, vector<int>& coins){
        
        vector<int> prev(amount+1,0), cur(amount+1,0);
        
        prev[0] = 1;
        cur[0] = 1;
        for(int i=1;i<=amount;i++){
            if(i % coins[0] == 0)
                prev[i] = 1;
            else
                prev[i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                int pick = 0, notpick = 0;
                notpick = prev[j];
                if(coins[i] <= j){
                    pick = cur[j - coins[i]];
                }
                cur[j] = pick + notpick;
            }
            prev = cur;
        }
        
        
        return prev[amount];
        
    }
};
