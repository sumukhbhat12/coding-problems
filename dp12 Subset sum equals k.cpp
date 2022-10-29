#include <bits/stdc++.h> 

//TOP DOWN APPROACH
int helper(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    if(k == 0){
        return 1;
    }
    if(n == 0){
        return k == arr[n] ? 1 : 0;
    }
    if(dp[n][k] != -1)
        return dp[n][k];
    
    int pick = 0, notpick = 0;
    notpick = helper(n-1,k,arr,dp);
    if(arr[n] <= k){
        pick = helper(n-1,k-arr[n],arr,dp);
    }
    
    return dp[n][k] = pick or notpick;
}


//BOTTOM UP APPROACH
int helper2(int n, int k, vector<int> &arr, vector<vector<int>> &dp){
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    
    if(arr[0] <= k)
        dp[0][arr[0]] = 1;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            int pick = 0, notpick = 0;
            notpick = dp[i-1][j];
            if(arr[i] <= j)
                pick = dp[i-1][j-arr[i]];
            dp[i][j] =  pick or notpick;
        }
    }
     return dp[n-1][k];
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    return helper2(n,k,arr,dp) == 1 ? true : false;
}
