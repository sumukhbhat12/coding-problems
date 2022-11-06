class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        //return helper(0,1,k,prices,dp);
        //return helper2(0,1,k,prices,dp);
        return helper3(0,1,k,prices);
    }
    
    //TOPDOWN APPROACH
    int helper(int n,int b, int t, vector<int>& prices, vector<vector<vector<int>>> &dp){
        
        if(t == 0)
            return 0;
        if(n == prices.size())
            return 0;
        
        if(dp[n][b][t] != -1)
            return dp[n][b][t];
        
        
        if(b){
            return dp[n][b][t] = max(-prices[n] + helper(n+1,!b,t,prices,dp), helper(n+1,b,t,prices,dp));
        }
        else{
            return dp[n][b][t] = max(prices[n] + helper(n+1,!b,t-1,prices,dp), helper(n+1,b,t,prices,dp));
        }
        
    }
    
    //BOTTOMUP APPROACH
    int helper2(int n,int b, int t, vector<int>& prices, vector<vector<vector<int>>> &dp){
        
        //base cases are if i == n or k == 0 then dp[i][j][k] = 0
        //the base case is initialized by default
        int m = prices.size();
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k = 1;k<=t;k++){
                    if(j){
                        dp[i][j][k] = max(-prices[i] + dp[i+1][!j][k], dp[i+1][j][k]);
                    }
                    else{
                        dp[i][j][k] = max(prices[i] + dp[i+1][!j][k-1], dp[i+1][j][k]);
                    }
                }
            }
        }
        
        return dp[n][b][t];
    }
    
    //SPACE OPTIMIZATION APPROACH
    int helper3(int n,int b, int t, vector<int>& prices){
        
        int m = prices.size();
        
        vector<vector<int>> next(2,vector<int>(t+1,0)), cur(2,vector<int>(t+1,0));
        
        
        //base cases are if i == n or k == 0 then next[j][k] = 0
        //the base case is initialized by default
        
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k = 1;k<=t;k++){
                    if(j){
                        cur[j][k] = max(-prices[i] + next[!j][k], next[j][k]);
                    }
                    else{
                        cur[j][k] = max(prices[i] + next[!j][k-1], next[j][k]);
                    }
                }
            }
            next = cur;
        }
        
        return next[b][t];
    }
    
};
