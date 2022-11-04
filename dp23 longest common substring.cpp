#include <bits/stdc++.h> 

int helper(int n, int m, string s1, string s2, vector<vector<int>> &dp){
    int maxi = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi,dp[i][j]);
            }
        }
    }
    
    return maxi;
}

int lcs(string &str1, string &str2){
    //    Write your code here.
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    return helper(n,m,str1,str2,dp);
}
