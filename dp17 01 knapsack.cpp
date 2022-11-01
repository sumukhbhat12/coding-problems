#include <bits/stdc++.h> 

//TOP DOWN APPROACH
int helper(int n, vector<int> &weight, vector<int> &value, int W,  vector<vector<int>> &dp){
    if(W == 0){
        return 0;
    }
    if(n == 0){
        if(weight[n] <= W)
            return value[n];
        else
            return 0;
    }
    if(dp[n][W] != -1)
        return dp[n][W];
    
    
    int pick = 0, notpick = 0;
    notpick = helper(n-1,weight,value,W,dp);
    if(weight[n] <= W){
        pick = value[n] + helper(n-1,weight,value,W - weight[n],dp);
    }
    
    return dp[n][W] = max(pick,notpick);
}

//BOTTOM UP APPROACH
int helper2(int n, vector<int> &weight, vector<int> &value, int W,  vector<vector<int>> &dp){
    for(int j=weight[0];j<=W;j++)
        dp[0][j] = value[0];
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            int pick = 0, notpick = 0;
            notpick = dp[i-1][j];
            if(weight[i] <= j)
                pick = value[i] + dp[i-1][j-weight[i]];
           
            dp[i][j] = max(pick, notpick);
        }
    }
    return dp[n][W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    return helper2(n-1,weight,value,maxWeight,dp); 
}
