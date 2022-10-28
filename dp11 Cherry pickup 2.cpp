class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        
        int ans = helper2(0,0,n-1,grid,dp);
        return ans;
    }
    
    //TOP DOWN APPROACH
    int helper(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j2 > grid[0].size()-1 || j1 > grid[0].size()-1 || j2 < 0){
            return -1e6;
        }
        if(i == grid.size()-1){
            if(j1 == j2)
                return grid[i][j1];
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        
        
        //each possible choice for i+1th row is either j = j-1, j = j+0 or j = j+1
        vector<int> dj = {-1,0,1};
        
        int maxi = -1e6;
        for(int p = 0;p<dj.size();p++){
            for(int q=0;q<dj.size();q++){
                //9 recursion paths
                //3 for robot1 and for each path of robot1, we need 3 paths for robot2
                //answer is the maximum sum of all possible paths
                
                if(j1 == j2){
                    //if both the robots end up in the same path, consider only once
                     maxi = max(maxi, grid[i][j1] + helper(i+1,j1+dj[p],j2+dj[q],grid,dp));
                }
                else{
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + helper(i+1, j1+dj[p], j2+dj[q], grid, dp));
                }
            }
        }
        
        
        return dp[i][j1][j2] = maxi;
    }
    
    //BOTTOM UP APPROACH
    int helper2(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        for(int k1=0;k1<grid[0].size();k1++){
            for(int k2=0;k2<grid[0].size();k2++){
                if(k1 == k2){
                    dp[grid.size()-1][k1][k2] = grid[grid.size()-1][k1];
                }
                else{
                    dp[grid.size()-1][k1][k2] = grid[grid.size()-1][k1] + grid[grid.size()-1][k2];
                }
            }
            
        }
        
        
        for(int i=grid.size()-2;i>=0;i--){
            for(int j1=0;j1<grid[0].size();j1++){
                for(int j2=0;j2<grid[0].size();j2++){
                    vector<int> dj = {-1,0,1};
                    int maxi = -1e6;
                    for(int p = 0;p<dj.size();p++){
                        for(int q=0;q<dj.size();q++){
                            int val = -1e6;
                            if(j1 == j2){
                                //if both the robots end up in the same path, consider only once
                                val = grid[i][j1];
                            }
                            else{
                                val = grid[i][j1] + grid[i][j2];
                               
                            }
                            if(j1+dj[p] >= 0 && j1+dj[p] < grid[0].size() && j2+dj[q] >= 0 && j2+dj[q] < grid[0].size()){
                                val += dp[i+1][j1+dj[p]][j2+dj[q]];
                            }
                            else{
                                val = -1e6;
                            }
                            
                            maxi = max(maxi,val);
                        }
                    }
                    
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        
        
        return dp[0][0][grid[0].size()-1];
    }
    
};
