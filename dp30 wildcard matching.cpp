class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        //vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //return helper2(n,m,s,p,dp);
        return helper3(n,m,s,p);
    }
    
  //TOPDOWN APPROACH
    bool helper(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        
        if(n < 0 && m < 0){
            return true;
        }
        
        if(m < 0 && n >= 0){
            return false;
        }
        
        if(n < 0 && m >= 0){
            for(int i=0;i<=m;i++){
                if(s2[i] != '*')
                    return false;
            }
            return true;
        }
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m] || s2[m] == '?'){
            return dp[n][m] = helper(n-1,m-1,s1,s2,dp);
        }
        else
        if(s2[m] == '*'){
            return dp[n][m] = helper(n,m-1,s1,s2,dp) || helper(n-1,m,s1,s2,dp);
        }
        else{
            return dp[n][m] = false;
        }
        
    }
    
    //BOTTOMUP APPROACH
    bool helper2(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        
        dp[0][0] = 1;
        
        for(int i=1;i<=m;i++){
            int flag = 0;
            //FOR THE FIRST ROW, THAT IS s1 = ""
            //IF ANY OF THE REMAINING CHARACTER IN s2 IS NOT A '*', THEN DP[0][M] IS 0. 
            for(int j=1;j<=i;j++){
                if(s2[j-1] != '*'){
                    flag = 1;
                    break;
                } 
            }
            //IF ALL THE REMAINING CHARACTERS IN THE STRING s2 ARE *, THEN DP[0][M] = 1.
            if(flag == 0)
                dp[0][i] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1] || s2[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                if(s2[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[n][m];
    }
    
    
    //SPACE OPTIMIZATION O(M)
    bool helper3(int n, int m, string &s1, string &s2){
        
        vector<int> prev(m+1,0), cur(m+1,0);
        
        prev[0] = 1;
        
        for(int i=1;i<=m;i++){
            int flag = 0;
            //FOR THE FIRST ROW, THAT IS s1 = ""
            //IF ANY OF THE REMAINING CHARACTER IN s2 IS NOT A '*', THEN DP[0][M] IS 0. 
            for(int j=1;j<=i;j++){
                if(s2[j-1] != '*'){
                    flag = 1;
                    break;
                } 
            }
            //IF ALL THE REMAINING CHARACTERS IN THE STRING s2 ARE *, THEN DP[0][M] = 1.
            if(flag == 0)
                prev[i] = 1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1] || s2[j-1] == '?'){
                    cur[j] = prev[j-1];
                }
                else
                if(s2[j-1] == '*'){
                    cur[j] = cur[j-1] || prev[j];
                }
                else{
                    cur[j] = 0;
                }
            }
            prev = cur;
        }
        
        return prev[m];
    }
    
};
