#include <bits/stdc++.h> 

//BOTTOM UP APPROACH (DOESN"T WORK FOR ANY CASE, NOT SURE WHY)
int helper2(int n, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(arr[0] == 0){
        dp[0][0] = 2;
    }
    else
        dp[0][0] = 1;
    
    if(arr[0] != 0 && arr[0] <= target){
        dp[0][arr[0]] = 1;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            int notpick = 0, pick = 0;
            notpick = dp[i-1][j];
            if(arr[i] <= target){
                pick = dp[i-1][j - arr[i]];
            }
            
            dp[i][j] = (pick + notpick) % (int)(1e9 + 7);
        }
    }
    
    return dp[n-1][target];
}

//TOP DOWN APPROACH (WORKS FOR ALL CASES)
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
    
    return dp[n][target] = (pick + notpick) % (int)(1e9 + 7);
}


int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    
    for(auto i : arr) sum += i;
    if(sum - d < 0)
        return 0;
    if(sum - d & 1)
        return 0;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
     return helper2(n,(sum - d) / 2, arr,dp);
}


