class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    visited[i][j] = 1;
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(int c, int r, vector<vector<char>>& grid, vector<vector<int>> &visited){
        int dir[] = {-1,0,1,0,-1}; // top -> [-1,0], right -> [0,1], bottom -> [1,0], left -> [0,-1]
        for(int i=0;i<4;i++){
            if(c+dir[i] >= 0 && r+dir[i+1] < grid[0].size() && c+dir[i] < grid.size() && r+dir[i+1] >= 0 && !visited[c+dir[i]][r+dir[i+1]] && grid[c+dir[i]][r+dir[i+1]] == '1'){
                visited[c+dir[i]][r+dir[i+1]] = 1;
                dfs(c+dir[i],r+dir[i+1],grid,visited);
            }
        }
    }
};
