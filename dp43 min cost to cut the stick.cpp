class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> temp(cuts.begin(),cuts.end());
        temp.insert(temp.end(),{n,0});
        sort(temp.begin(),temp.end());
        vector<vector<int>> dp(temp.size()+1,vector<int>(temp.size()+1,0));
        return helper2(1,temp.size()-2,temp,dp);
    }
    
    //TOPDOWN APPROACH
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(j < i)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int cost = 0;
        int m = cuts.size();
        int mini = INT_MAX;
        
        for(int k=i;k<=j;k++){
            cost = cuts[j+1] - cuts[i-1] + helper(i,k-1,cuts,dp) + helper(k+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        
        
        return dp[i][j] = mini;
    }
    
    //BOTTOMUP APPROACH
    int helper2(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        
        int m = cuts.size();
        
        for(int i=m-2;i>=1;i--){
            for(int j=1;j<m-1;j++){
                if(i <= j){
                    int cost = 0, mini = INT_MAX;
                    for(int k=i;k<=j;k++){
                        cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                        mini = min(mini,cost);
                    }
                    
                    dp[i][j] = mini;
                }
            }
        }
        
        return dp[i][j];
    }
    
};
