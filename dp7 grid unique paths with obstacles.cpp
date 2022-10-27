class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //return helper(m-1,n-1,obstacleGrid,dp);
        return helper2(m-1,n-1,obstacleGrid,dp);
    }
    
    //TOP DOWN
    int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(m < 0 || n < 0){
            return 0;
        }
        
        if(obstacleGrid[m][n] == 1){
            return 0;
        }
        
        if(m == 0 && n == 0){
            return 1;
        }
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        
        return dp[m][n] = helper(m-1,n,obstacleGrid,dp) + helper(m,n-1,obstacleGrid,dp);
    }
    
    
    //BOTTOM UP
    int helper2(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        dp[0][0] = 1;
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    int up = 0, left = 0;
                    if(i > 0)
                        up = dp[i-1][j];
                    if(j > 0)
                        left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        
        //return dp[m][n];
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dp[m][n];
    }
};
