
//TOPDOWN APPROACH
int helper(int n, int length, vector<int> &price, vector<vector<int>> &dp){
    if(n == 1){
        return length * price[n-1];
    }
    
    if(dp[n][length] != -1)
        return dp[n][length];
    
    int pick = 0, notpick = 0;
    
    notpick = helper(n-1,length,price,dp);
    
    if(n <= length){
        pick = price[n-1] + helper(n,length - n,price,dp);
    }
    
    return dp[n][length] = max(pick, notpick);
}

//BOTTOMUP APPROACH
int helper2(int n, int length, vector<int> &price, vector<vector<int>> &dp){
    for(int i=1;i<=length;i++)
        dp[1][i] = i * price[0];
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=length;j++){
            
            int pick = 0, notpick = 0;
            
            notpick = dp[i-1][j];
            
            if(i <= j){
                pick = price[i-1] + dp[i][j-i];
            }
            
            dp[i][j] = max(pick,notpick);
        }
    }
    
    return dp[n][length];
}

//SPACE OPTIMIZATION O(N)
int helper3(int n, int length, vector<int> &price){
    vector<int> prev(length+1,0);

    for(int i=1;i<=length;i++){
        prev[i] = i * price[0];
    }
        
    for(int i=2;i<=n;i++){
        for(int j=1;j<=length;j++){
            
            int pick = 0, notpick = 0;
            
            notpick = prev[j];
            
            if(i <= j){
                pick = price[i-1] + prev[j-i];
            }
            
            prev[j] = max(pick,notpick);
        }
    }
    
    return prev[length];
}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    //vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    return helper3(n,n,price);
}
