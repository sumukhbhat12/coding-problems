#include <bits/stdc++.h> 

//TOP DOWN APPRAOCH (WORKS FOR ALL CASES)
int helper(int n, int target, vector<int> &num, vector<vector<int>> &dp){
    
    if(n == 0){
        if(target == 0 && num[n] == 0){
            return 2;
        }
        if(target == 0 || num[n] == target){
            return 1;
        }
        else
            return 0;
    }
    
    if(dp[n][target] != -1)
        return dp[n][target];
    int pick = 0,notpick = 0;
    notpick = helper(n-1,target,num,dp);
    if(num[n] <= target)
        pick = helper(n-1,target - num[n],num,dp);
    
    return dp[n][target] = pick + notpick;
}

//BOTTOMUP APPRAOCH (DOESN"T WORK FOR ALL CASES)
int helper2(int n, int target, vector<int> &num, vector<vector<int>> &dp){
    if(num[0] == 0){
        dp[0][0] = 2;
    }
    else
        dp[0][0] = 1;
    
    if(num[0] != 0 && num[0] <= target){
        dp[0][num[0]] = 1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            int notpick = 0, pick = 0;
            notpick = dp[i-1][j];
            if(num[i] <= target){
                pick = dp[i-1][j - num[i]];
            }
            
            dp[i][j] = pick + notpick;
        }
    }
    
    return dp[n][target];
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    return helper2(n-1,tar,num,dp);
}
