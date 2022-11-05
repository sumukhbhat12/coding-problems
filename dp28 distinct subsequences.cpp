class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        //vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(m+1,0));
        return helper3(n,m,s,t);
    }
    
  //TOPDOWN APPROACH
    int helper(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        if(m < 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m]){
            return dp[n][m] = helper(n-1,m-1,s1,s2,dp) + helper(n-1,m,s1,s2,dp);
        }
        else{
            return dp[n][m] = helper(n-1,m,s1,s2,dp);
        }
    }
    
    //BOTTOMUP APPROACH
    int helper2(int n, int m, string s1, string s2, vector<vector<unsigned int>> &dp){
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
    
    //SPACE OPTIMIZATION O(M)
    int helper3(int n, int m, string s1, string s2){
        vector<unsigned int> cur(m+1,0), prev(m+1,0);
        
        prev[0]=1;
        cur[0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    cur[j] = prev[j-1] + prev[j];
                }
                else{
                    cur[j] = prev[j];
                }
            }
            prev = cur;
        }
        return prev[m];
    }
    
};
