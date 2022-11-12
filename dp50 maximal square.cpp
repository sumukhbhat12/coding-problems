class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        int ans = 0;
        
        //for topdown approach
        /*
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,helper(i,j,matrix,dp));
            }
        }
        */
        
        //for bottomup approach
        //ans = helper2(0,0,matrix,dp);
        
        ans = helper3(0,0,matrix);
        return ans*ans;
    }
    
    //TOPDOWN APPROACH
    //returns the max length of the largest square where m and n are the top left corner of the square
    int helper(int m, int n, vector<vector<char>>& matrix, vector<vector<int>> &dp){
        
        if(m == matrix.size() || n == matrix[0].size()){
            return 0;
        }
        
        if(matrix[m][n] == '0')
            return 0;
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        return dp[m][n] = 1 + min(helper(m,n+1,matrix,dp), min(helper(m+1,n,matrix,dp), helper(m+1,n+1,matrix,dp)));
        
        
    }
    
    //BOTTOMUP APPROACH
    int helper2(int m, int n, vector<vector<char>>& matrix, vector<vector<int>> &dp){
        
        int p = matrix.size();
        int q = matrix[0].size();
        
        int ans = 0;
        for(int i=p-1;i>=m;i--){
            for(int j=q-1;j>=n;j--){
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else{
                    dp[i][j] = 1 + min(dp[i][j+1], min(dp[i+1][j], dp[i+1][j+1]));
                }
                ans = max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
    
    //SPACE OPTIMIZATION O(N)
    
    int helper3(int m, int n, vector<vector<char>>& matrix){
        
        int p = matrix.size();
        int q = matrix[0].size();
        
        vector<int> next(q+1,0), cur(q+1,0);
        
        int ans = 0;
        for(int i=p-1;i>=m;i--){
            for(int j=q-1;j>=n;j--){
                if(matrix[i][j] == '0')
                    cur[j] = 0;
                else{
                    cur[j] = 1 + min(cur[j+1], min(next[j], next[j+1]));
                }
                ans = max(ans,cur[j]);
            }
            next = cur;
                                                               
        }
        
        return ans;
    }
    
};
