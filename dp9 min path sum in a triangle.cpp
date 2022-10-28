class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(m,1e9);
        return helper3(0,0,m-1,triangle,dp);
    }
    
    //TOPDOWN APPROACH
    int helper(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(i == m){
            return triangle[i][j];
        }
        
        if(dp[i][j] != 1e9)
            return dp[i][j];
        
        int bottom = INT_MAX, bottomright = INT_MAX;
        
        bottom = helper(i+1,j,m,triangle,dp);
        bottomright = helper(i+1,j+1,m,triangle,dp);
        
        return dp[i][j] = triangle[i][j] + min(bottom, bottomright);
        
    }
    
    //BOTTOMUP APPROACH
    int helper2(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        for(int a=m;a>=0;a--){
            for(int b=0;b<=a;b++){
                if(a == m){
                    dp[a][b] = triangle[a][b];
                }
                else{
                    dp[a][b] = triangle[a][b] + min(dp[a+1][b], dp[a+1][b+1]);
                }
                
            }
        }
        
        return dp[0][0];
    }
    
    //SPACE OPTIMIZATION O(N)
    int helper3(int i, int j, int m, vector<vector<int>>& triangle, vector<int> &dp){
        vector<int> temp(m+1);
        for(int a=m;a>=0;a--){
            for(int b=0;b<=a;b++){
                if(a == m){
                    dp[b] = triangle[a][b];
                }
                else{
                    temp[b] = triangle[a][b] + min(dp[b], dp[b+1]);
                    
                }
            }
            //to avoid overwriting dp with 0s since at a == m, temp only has 0s
            if(a != m)
                dp = temp;
        }
        return dp[0];
    }
};
