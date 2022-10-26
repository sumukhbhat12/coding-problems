int helper(int n, vector<vector<int>> &points, int prev,  vector<vector<int>> &dp);
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(points.size(),vector<int>(points[0].size()+1,-1));
    return helper(n-1,points,3,dp);
}

int helper(int n, vector<vector<int>> &points, int prev, vector<vector<int>> &dp){
    for(int i=0;i<points[0].size();i++){
        int maxi = 0;
        for(int j=0;j<points[0].size();j++){
            if(j != i){
                maxi = max(maxi,points[0][j]);
            }
        }
        dp[0][i] = maxi;
    }
    
    for(int i=1;i<points.size();i++){
        for(int j=0;j<points[0].size();j++){
            int maxi = 0;
            for(int k=0;k<points[0].size();k++){
                if(k != j){
                    maxi = max(maxi,dp[i-1][k] + points[i][k]);
                }
            }
            dp[i][j] = maxi;
        }
    }
    int maxi = 0;
    for(int i=0;i<dp[0].size();i++){
        maxi = max(maxi,dp[n][i]);
    }
    return maxi;
        
}
