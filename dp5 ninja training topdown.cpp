int helper(int n, vector<vector<int>> &points, int prev,  vector<vector<int>> &dp);
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(points.size(),vector<int>(points[0].size()+1,-1));
    return helper(n-1,points,3,dp);
}

int helper(int n, vector<vector<int>> &points, int prev, vector<vector<int>> &dp){
    if(n == 0){
        int maxi = -1;
        for(int i=0;i<points[0].size();i++){
            if(i != prev)
                maxi = max(maxi,points[n][i]);
        }
        return maxi;
    }
    
    if(dp[n][prev] != -1) 
        return dp[n][prev];
    
    int maxi = -1;
    for(int i=0;i<points[n].size();i++){
        if(i != prev){
            int choose = points[n][i] + helper(n-1,points,i,dp);
            maxi = max(maxi,choose);
        }
    }
    dp[n][prev] = maxi;
    return dp[n][prev];
        
}
