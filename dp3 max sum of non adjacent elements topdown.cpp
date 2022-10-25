#include <bits/stdc++.h> 
int helper(int n, vector<int> &nums, vector<int> &dp);
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size()+1,-1);
    return helper(nums.size()-1,nums,dp);
}

int helper(int n, vector<int> &nums, vector<int> &dp){
    if(n == 0){
        return nums[n];
    }
    if(n < 0){
        return 0;
    }
    int pick = INT_MIN;
    int notpick = INT_MIN;
    if(dp[n] == -1){
        pick = nums[n] + helper(n-2,nums,dp);
        notpick = helper(n-1,nums,dp);
        dp[n] = max(pick,notpick);
    }
    return dp[n];
}
