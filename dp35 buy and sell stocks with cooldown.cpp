class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(2,0)));
        //return helper2(0,1,0,prices,dp);
        return helper3(0,1,0,prices);
    }
    
    //TOPDOWN APPROACH
    int helper(int n, int b, int c, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(n == prices.size())
            return 0;
        
        if(dp[n][b][c] != -1)
            return dp[n][b][c];
        
        if(c == 1){
            return dp[n][b][c] = helper(n+1,b,!c,prices,dp);
        }
        
        if(b){
            return dp[n][b][c] = max(-prices[n] + helper(n+1,!b,c,prices,dp), helper(n+1,b,c,prices,dp));
        }
        else{
            return dp[n][b][c] = max(prices[n] + helper(n+1,!b,!c,prices,dp), helper(n+1,b,c,prices,dp));
        }
    }
    
    //BOTTOMUP APPROACH
    int helper2(int n, int b, int c, vector<int> &prices, vector<vector<vector<int>>> &dp){
        int m = prices.size();
        
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k>=0;k--){
                    
                    if(k == 1)
                        dp[i][j][k] = dp[i+1][j][!k];
                    else
                    if(j){
                        dp[i][j][k] = max(-prices[i] + dp[i+1][!j][k], dp[i+1][j][k]);
                    }
                    else{
                        dp[i][j][k] = max(prices[i] + dp[i+1][!j][!k], dp[i+1][j][k]);
                    }
                }
            }
        }
        
        return dp[n][b][c];
    }
    
    //SPACE OPTIMIZATION O(1)
    int helper3(int n, int b, int c, vector<int> &prices){
        int m = prices.size();
        
        vector<vector<int>>next(2,vector<int>(2,0)), cur(2,vector<int>(2,0));
        
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k>=0;k--){
                    
                    if(k == 1)
                        cur[j][k] = next[j][!k];
                    else
                    if(j){
                        cur[j][k] = max(-prices[i] + next[!j][k], next[j][k]);
                    }
                    else{
                        cur[j][k] = max(prices[i] + next[!j][!k], next[j][k]);
                    }
                }
            }
            next = cur;
        }
        
        return next[b][c];
    }
    
};
