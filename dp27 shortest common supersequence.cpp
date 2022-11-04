class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        string ans = "";
        int lengthOfLcs = helper(n,m,str1,str2,dp);
        
        //backtrack from dp[n][m] to dp[0][0] in the dp table
        int i = n, j = m;
        while(i > 0 && j > 0){
            //IF THE STRING CHARACTERS ARE SAME
            if(str1[i-1] == str2[j-1]){
                    //PUSH ANY ONE TO THE ANS AND MOVE DIAGONALLY TOP LEFT OF THE DP ARRAY
                    ans.push_back(str1[i-1]);
                    i--;
                    j--;
            }
            else{
                //IF STRING CHARACTERS ARE NOT THE SAME
                //IF THE LEFT VALUE IS MORE THAN THE TOP VALUE IN THE DP ARRAY
                if(dp[i][j-1] > dp[i-1][j]){
                    //PUSH THE COLUMN CHARACTER TO THE ANS AND MOVE LEFT
                    ans.push_back(str2[j-1]);
                    j--;
                }
                else{
                    //PUSH THE ROW CHARACTER TO THE ANS AND MOVE TOP
                    ans.push_back(str1[i-1]);
                    i--;
                }
            }
           
        }
        //AT THE END EITHER i BECOMES 0 or j BECOMES 0, HENCE ONE OF THEM THAT HAS NOT BECOME 0 NEEDS TO BE
        //ADDED TO THE ANS TILL IT BECOMES 0
        while(i > 0){
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j > 0){
            ans.push_back(str2[j-1]);
            j--;
        }
        //SINCE WE BACKTRACKED FROM THE DP[N][M] to DP[0][0] THEN WE NEED TO REVERSE THE ANS STRING
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    //FIND THE LONGEST COMMON SUBSEQUENCE
    int helper(int n, int m, string s1, string s2, vector<vector<int>> &dp){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    
};
