#include <bits/stdc++.h> 
int helper(int n, vector<int> &heights, vector<int> &dp);
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return helper(n-1,heights,dp);
}

int helper(int n, vector<int> &heights, vector<int> &dp){
   if(n == 0){
       return 0;
   }
    if(n == 1){
        return abs(heights[n] - heights[n-1]);
    }
    if(dp[n] == -1){
        dp[n] = min(helper(n-1,heights,dp) + abs(heights[n] - heights[n-1]), helper(n-2,heights,dp) + abs(heights[n] - heights[n-2]));
    }
    return dp[n];
}
