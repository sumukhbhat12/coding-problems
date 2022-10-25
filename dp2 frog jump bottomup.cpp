#include <bits/stdc++.h> 
int helper(int n, vector<int> &heights, vector<int> &dp);
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return helper(n-1,heights,dp);
}

int helper(int n, vector<int> &heights, vector<int> &dp){
    dp[0] = 0;
    dp[1] = dp[0] + abs(heights[1] - heights[0]);
    for(int i=2;i<=n;i++){
        dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]),dp[i-2] + abs(heights[i] - heights[i-2]));
    }
    return dp[n];
}
