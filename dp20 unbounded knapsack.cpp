#include <bits/stdc++.h> 

//TOPDOWN APPROACH
int helper(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(w == 0){
        return 0;
    }
    if(n == 0){
       return w / weight[0] * profit[0];
    }
    if(dp[n][w] != -1)
        return dp[n][w];
    int pick = 0, notpick = 0;
    notpick = helper(n-1,w,profit,weight,dp);
    if(weight[n] <= w){
        pick = profit[n] + helper(n,w - weight[n], profit, weight,dp);
    }
    
    return dp[n][w] = max(pick,notpick);
}

//BOTTOMUP APPROACH
int helper2(int n, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=w;i++){
        dp[0][i] = (i / weight[0]) * profit[0];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            int pick = 0, notpick = 0;
            notpick = dp[i-1][j];
            if(weight[i] <= j){
                pick = profit[i] + dp[i][j - weight[i]];
            }
            dp[i][j] = max(pick,notpick);
        }
    }
    
    return dp[n][w];
}

//SPACE OPTIMIZATION O(w)
int helper3(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<int> prev(w+1,0), cur(w+1,0);
  
    prev[0] = 0;
    cur[0] = 0;
    for(int i=1;i<=w;i++){
        prev[i] = (i / weight[0]) * profit[0];
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            int pick = 0, notpick = 0;
            notpick = prev[j];
            if(weight[i] <= j){
                pick = profit[i] + cur[j - weight[i]];
            }
            cur[j] = max(pick,notpick);
        }
        prev = cur;
    }
    
    return prev[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    //vector<vector<int>> dp(n,vector<int>(w+1,0));
    return helper3(n-1,w,profit,weight);
}
