class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        //return helper(0,1,prices,fee,dp);
        //return helper2(0,1,prices,fee,dp);
        return helper3(0,1,prices,fee);
    }
    
    //TOPDOWN APPROACH
    int helper(int n, int b, vector<int> &prices, int fee, vector<vector<int>> &dp){
        if(n == prices.size()){
            return 0;
        }
        
        if(dp[n][b] != -1)
            return dp[n][b];
        
        if(b){
            return dp[n][b] = max(-prices[n] + helper(n+1,!b,prices,fee,dp), helper(n+1,b,prices,fee,dp));
        }
        else{
            return dp[n][b] = max(prices[n] - fee + helper(n+1,!b,prices,fee,dp), helper(n+1,b,prices,fee,dp));
        }
    }
    
    //BOTTOMUP APPROACH
    int helper2(int n, int b, vector<int> &prices, int fee, vector<vector<int>> &dp){
        int m = prices.size();
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    dp[i][j] = max(-prices[i] + dp[i+1][!j], dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(prices[i] - fee + dp[i+1][!j], dp[i+1][j]);
                }
            }
        }
        
        return dp[n][b];
    }
    
    
    int helper3(int n, int b, vector<int> &prices, int fee){
        vector<int> next(2,0), cur(2,0);
        int m = prices.size();
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    cur[j] = max(-prices[i] + next[!j], next[j]);
                }
                else{
                    cur[j] = max(prices[i] - fee + next[!j], next[j]);
                }
            }
            next = cur;
        }
        
        return next[b];
    }
    
};
