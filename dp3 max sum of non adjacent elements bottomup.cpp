#include <bits/stdc++.h> 
int helper(int n, vector<int> &nums, vector<int> &dp);
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp(nums.size()+1,-1);
    return helper(nums.size(),nums,dp);
}

int helper(int n, vector<int> &nums, vector<int> &dp){
    dp[0] = nums[0];
    for(int i=1;i<n;i++){
        int pick = INT_MIN, notpick = INT_MIN;
        notpick = dp[i-1];
        pick = nums[i];
        if(i-2 >= 0){
            pick += dp[i-2];
        }
        dp[i] = max(pick,notpick);
    }
    return dp[n-1];
}
