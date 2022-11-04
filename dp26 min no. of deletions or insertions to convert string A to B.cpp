#include <bits/stdc++.h> 

int helper(int n, int m, string s1, string s2){
    vector<int> prev(m+1,0), cur(m+1,0);
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


int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.length();
    int m = ptr.length();
    int commonSubsequence = helper(n,m,str,ptr);
    return n - commonSubsequence + m - commonSubsequence;
}
