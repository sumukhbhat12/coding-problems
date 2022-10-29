#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int sum = 0;
    
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    
    //BOTTOM UP APPROACH OF SUBSET SUM WITH TARGET
    for(int i = 0;i<n;i++)
        dp[i][0] = 1;
    if(arr[0] <= sum)
        dp[0][arr[0]] = 1;
    
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            int pick = 0, notpick = 0;
            notpick = dp[i-1][j];
            if(arr[i] <= j)
                pick = dp[i-1][j-arr[i]];
            
            dp[i][j] = pick or notpick;
        }
    }
    
    int mini = 1e9;
    //sum/2 for optimisation because, i is the target of subset 1 and sum - i is the target of subset 2
    //after i = sum/2, the sum - i will be same values as i from 0 to sum/2
    for(int i=0;i<=sum/2;i++){
        if(dp[n-1][i] == 1){
            mini = min(mini, (sum - i) - i);
        }
    }
    return mini;
}
