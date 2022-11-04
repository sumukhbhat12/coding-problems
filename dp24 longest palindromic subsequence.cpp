class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return helper2(n,n,s,t,dp);
    }
    
    //FIND LONGEST COMMON SUBSEQUENCE
    //TOPDOWN GIVES TLE 🤦‍
    int helper(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        if(n < 0 || m < 0){
            return 0;
        }
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m]){
            return dp[n][m] = 1 + helper(n-1,m-1,s1,s2,dp);
        }
        else{
            return dp[n][m] = max(helper(n-1,m,s1,s2,dp), helper(n,m-1,s1,s2,dp));
        }
    }
    
    //BOTTOMUP APPROACH
    int helper2(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    
};
