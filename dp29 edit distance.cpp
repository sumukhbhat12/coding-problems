class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        //vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return helper2(n,m,word1,word2,dp);
        return helper3(n,m,word1,word2);
    }
    
    //TOPDOWN APPROACH
    int helper(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        if(m < 0){
           return n+1;              //delete the remaining characters
        }
        
        if(n < 0){
            return m+1;             //insert the remaining characters
        }
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m]){
            return helper(n-1,m-1,s1,s2,dp);
        }
        else{
            int insert = 0, deletee = 0, replace = 0;
            
            insert = 1 + helper(n,m-1,s1,s2,dp);
            
            deletee = 1 + helper(n-1,m,s1,s2,dp);
            
            replace = 1 + helper(n-1,m-1,s1,s2,dp);
            
            return dp[n][m] = min(insert, min(deletee,replace));
        }
    }
    
    //BOTTOMUP APPROACH
    int helper2(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        for(int i=0;i<=m;i++){
            dp[0][i] = i;
        }
        
        for(int i=1;i<=n;i++){
            dp[i][0] = i;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int insert = 0, deletee = 0, replace = 0;
            
                    insert = 1 + dp[i][j-1];

                    deletee = 1 + dp[i-1][j];

                    replace = 1 + dp[i-1][j-1];

                    dp[i][j] = min(insert, min(deletee,replace));
                }
            }
        }
        
        return dp[n][m];
    }
    
    //SPACE OPTIMIZATION O(M).
    int helper3(int n, int m, string &s1, string &s2){
        vector<int> prev(m+1,0), cur(m+1,0);
        
        for(int i=0;i<=m;i++){
            prev[i] = i;
        }
        
        cur[0] = 0;
        
        for(int i=1;i<=n;i++){
            cur[0] = i;
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    cur[j] = prev[j-1];
                }
                else{
                    int insert = 0, deletee = 0, replace = 0;
            
                    insert = 1 + cur[j-1];

                    deletee = 1 + prev[j];

                    replace = 1 + prev[j-1];

                    cur[j] = min(insert, min(deletee,replace));
                }
            }
            prev = cur;
        }
        
        return prev[m];
    }
    
    
};
