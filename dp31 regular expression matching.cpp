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
        
        if(m < 0){
            return false;
        }
        
        if(n < 0){
            for(int i = m;i>=0;i-=2){
                //if s1 = "" and s2 = "a*b*c*", then we start from m-1 and check if s2[m-1] is not *
                //if it is *, then we decrement by 2 to skip the previous character to *.
                if(s2[i] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(s1[n] == s2[m] || s2[m] == '.'){
            return dp[n][m] = helper(n-1,m-1,s1,s2,dp);
        }
        else
        if(s2[m] == '*'){
            
            if(s2[m-1] == s1[n] || s2[m-1] == '.'){
                //if the previous character to the * matches with s1, we can either take 0 characters from s1
                //and continue by skipping the * in s2
                //or we can include 1 character from s1 and continue solving recursively while including 
                //* character again in the next recursion
                return dp[n][m] = helper(n,m-2,s1,s2,dp) || helper(n-1,m,s1,s2,dp);
            }
            else{
                //if it doesn't match then we can only take 0 characters from s1 and then have no other choice
                //but to skip the * character and continue solving recursively
                //for s1[1...n] and s2[1...m-2]
                return dp[n][m] = helper(n,m-2,s1,s2,dp);
            }
            
        }
        else{
            return dp[n][m] = false;
        }
        
    }
    
    //BOTTOMUP APPROACH
    bool helper2(int n, int m, string &s1, string &s2, vector<vector<int>> &dp){
        dp[0][0] = 1;
        
        //starts from 2 because if i == 1 then the flag will be unset and the dp[0][1] will be 1
        for(int i=2;i<=m;i++){
            for(int j=i;j>=2;j-=2){
                if(s2[j-1] != '*'){
                    break;
                }
                else{
                    dp[0][i] = dp[0][i-2];
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1] || s2[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                if(s2[j-1] == '*'){
                    if(s1[i-1] == s2[j-2] || s2[j-2] == '.'){
                        dp[i][j] = dp[i][j-2] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        
        return dp[n][m];
        
    }
    
    
    bool helper3(int n, int m, string &s1, string &s2){
        
        vector<int> prev(m+1,0), cur(m+1,0);
        
        prev[0] = 1;
        
        //starts from 2 because if i == 1 then the flag will be unset and the dp[0][1] will be 1
        for(int i=2;i<=m;i++){
            for(int j=i;j>=2;j-=2){
                if(s2[j-1] != '*'){
                    break;
                }
                else{
                    prev[i] = prev[i-2];
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1] || s2[j-1] == '.'){
                    cur[j] = prev[j-1];
                }
                else
                if(s2[j-1] == '*'){
                    if(s1[i-1] == s2[j-2] || s2[j-2] == '.'){
                        cur[j] = cur[j-2] || prev[j];
                    }
                    else{
                        cur[j] = cur[j-2];
                    }
                }
                else{
                    cur[j] = 0;
                }
            }
            prev = cur;
        }
        
        //dp table for testing
        /*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        */
        
        return prev[m];
        
    }
    
};
