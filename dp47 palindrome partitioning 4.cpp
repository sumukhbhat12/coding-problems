class Solution {
public:
    vector<vector<int>> dp2;
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        dp2.resize(n,vector<int> (n,-1));
        
        return helper2(0,2,n-1,s,dp);
    }
    
    
    //PREPROCESSING THE PALINDROME WITH DP
    int isPalindrome(int i, int j, string &s){
        if (i >= j) 
            return true;
        
		if (dp2[i][j] != -1) 
            return dp2[i][j];
        
		if (s[i] == s[j]) 
            return dp2[i][j] = isPalindrome(i + 1, j - 1,s);
        
		return dp2[i][j] = false;
    }
    
    
    //TOPDOWN
    int helper(int i, int c, int n, string &s, vector<vector<int>> &dp){
        if(i == n){
            return c==0;
        }
        
        if(c == 0){
            return isPalindrome(i,n,s);
        }
        
        if(dp[i][c] != -1)
            return dp[i][c];
        
        int ans = 0;
        int temp;
        for(int k=i;k<n;k++){
            if(isPalindrome(i,k,s)){
                temp = true && helper(k+1,c-1,n,s,dp);
                ans = ans or temp;
                if(ans == true)
                    break;
            }
        }
        
        return dp[i][c] = ans;
    }
    
    //BOTTOMUP
    int helper2(int i, int c, int n, string &s, vector<vector<int>> &dp){
        dp[n][0] = 1;
        for(int i=0;i<=n;i++){
            dp[i][0] = isPalindrome(i,n,s);
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=c;j++){
                int ans = 0;
                int temp;
                for(int k=i;k<n;k++){
                    if(isPalindrome(i,k,s)){
                        temp = true && dp[k+1][j-1];
                        ans = ans or temp;
                        if(ans == true)
                            break;
                    }
                }

                dp[i][j] = ans;
            }
        }
        return dp[i][c];
    }
    
};
