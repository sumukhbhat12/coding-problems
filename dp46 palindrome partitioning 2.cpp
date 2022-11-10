class Solution {
public:
    int minCut(string s) {
        //vector<int> dp(s.length()+1,0);
        //return helper2(0,s.length()-1,s,dp);
        return helper3(0,s.length()-1,s);
    }
    
    //TOPDOWN APPROACH
    int helper(int i, int j, string &s, vector<int> &dp){
        if(i > j || isPalindrome(i,j,s)){
            return 0;
        }
        
        if(dp[i] != -1)
            return dp[i];
        
        int mini = INT_MAX;
        int cuts;
        for(int k=i;k<j;k++){
            //if left half is not a palindrome, there's no need to partition at that point
            //this is to save time otherwise if we do cuts = 1 + helper(i,k-1) + helper(k,j) , we will get TLE
            if(isPalindrome(i,k,s)){
                cuts = 1 + helper(k+1,j,s,dp);
                mini = min(mini,cuts);
            }
            
        }
        if(mini == INT_MAX){
            mini = 0;
        }
        return dp[i] = mini;
    }
    
    int isPalindrome(int i, int j, string &s){
        
        
        while(i<j){
            if(s[i++] != s[j--]){
                return 0;
            }
        }
        return 1;
    }
    
    //BOTTOMUP APPROACH
    int helper2(int i, int j, string &s, vector<int> &dp){
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            
            if(isPalindrome(i,j,s)){
                continue;
            }
            
            int mini = INT_MAX;
            int cuts;
            for(int k=i;k<j;k++){
                
                if(isPalindrome(i,k,s)){
                    cuts = 1 + dp[k+1];
                    mini = min(mini,cuts);
                }

            }
            if(mini == INT_MAX){
                mini = 0;
            }
            dp[i] = mini;
        }
        return dp[i];
    }
    
};
