class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        //vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int longestPalindromicSubsequence = helper(n,n,s,t);
        //THE MINIMAL INSERTIONS IS THE TOTAL LENGTH OF THE STRING - THE LONGEST PALINDROMIC SUBSEQUENCE
        return n - longestPalindromicSubsequence;
    }
    
    
    //FIND LONGEST COMMON SUBSEQUENCE BETWEEN A STRING AND ITS REVERSE TO GET THE LONGEST PALINDROMIC SUBSEQUENCE OF A STRING
    int helper(int n, int m, string s1, string s2){
        vector<int> cur(m+1,0), prev(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    cur[j] = 1 + prev[j-1];
                }
                else{
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        
        return prev[m];
        
    }
    
};
