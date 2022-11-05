class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<int>> dp(n+1,vector<int>(2,0));
        //return helper2(0,1,prices,dp);
        return helper3(0,1,prices);
    }
    
    //TOPDOWN APPROACH
    int helper(int n, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(n == prices.size()){
            return 0;
        }
        
        if(dp[n][buy] != -1)
            return dp[n][buy];
        
        if(buy){
            return dp[n][buy] = max(-prices[n] + helper(n+1,!buy,prices,dp), helper(n+1,buy,prices,dp));
        }
        else{
            return dp[n][buy] = max(prices[n] + helper(n+1,!buy,prices,dp), helper(n+1,buy,prices,dp));
        }
    }
    
  //BOTTOMUP APPROACH
    int helper2(int n, int buy, vector<int> &prices, vector<vector<int>> &dp){
        dp[prices.size()][0] = 0;
        dp[prices.size()][1] = 0;
        
        for(int i = prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    dp[i][j] = max(-prices[i] + dp[i+1][!j], dp[i+1][j]);
                }
                else{
                    dp[i][j] = max(prices[i] + dp[i+1][!j], dp[i+1][j]);
                }
            }
        }
        
        return dp[n][buy];
    }
    
    //SPACE OPTIMIZATION O(1)
    int helper3(int n, int buy, vector<int> &prices){
        vector<int> prev(2,0);
        prev[0] = 0;
        prev[1] = 0;
        
        for(int i = prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    prev[j] = max(-prices[i] + prev[!j], prev[j]);
                }
                else{
                    prev[j] = max(prices[i] + prev[!j], prev[j]);
                }
            }
        }
        
        return prev[buy];
    }
    
    
};
