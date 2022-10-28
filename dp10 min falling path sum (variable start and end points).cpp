class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            mini = min(mini, helper(n-1,i,matrix,dp));
            
        }
        return mini;
    }
    
    //TOP DOWN APPROACH
    int helper(int n, int i, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(n == 0){
            return matrix[n][i];
        }
        
        if(dp[n][i] != -1)
            return dp[n][i];
        
        int left = 1e9, mid = 1e9, right = 1e9;
        
        if(i > 0)
            left = helper(n-1,i-1,matrix,dp);
        mid = helper(n-1,i,matrix,dp);
        if(i < matrix.size()-1)
            right = helper(n-1,i+1,matrix,dp);
        
        return dp[n][i] = matrix[n][i] + min(left, min(mid,right));
    }
    
    //BOTTOM UP APPRAOCH
    int helper2(int n, int i, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        for(int i=0;i<=n;i++){
            dp[0][i] = matrix[0][i];
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                int left = 1e9, mid = 1e9, right = 1e9;
                if(j > 0)
                    left = dp[i-1][j-1];
                mid = dp[i-1][j];
                if(j < matrix.size()-1)
                    right = dp[i-1][j+1];
                
                dp[i][j] = matrix[i][j] + min(left,min(mid,right));
            }
        }
        
        return dp[n][i];
    }
};
