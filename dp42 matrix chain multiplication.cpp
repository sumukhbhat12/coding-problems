#include <bits/stdc++.h> 

//BOTTOMUP APPROACH
int helper2(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    int N = arr.size();
    for(int i=0;i<N;i++){
        dp[i][i] = 0;
    }
    
    for(int i=N-1;i>=1;i--){
        for(int j=i+1;j<N;j++){
            int cost = 0;
            int mini = INT_MAX;
            for(int k=i;k<j;k++){
                cost = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
        mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[i][j];
}

//TOPDOWN APPROACH
int helper(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    //i == j represents that we have divided the array into only 1 matrix, whose multiplication
    //is 0
    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int cost = -1;
    int mini = INT_MAX;
    //we are checking for all possible partitions of ABCD
    //A BCD, AB CD, ABC D
    for(int k=i;k<j;k++){
        //cost of multiplying 2 partitions
        //ABCD --> A BCD --> A * BCD
        //i-1 represents A's start, k represents A's end, j represents BCD's end
        //AB CD --> if A = 1x3 and B = 3x5 then AB = 1x5
        //if C = 5x6 and D = 6x9 then CD = 5x9
        //then AB x CD = 1x5 * 5x9
        //cost = 1*5*9 according to the matrix multiplication
        
        cost = (arr[i-1] * arr[k] * arr[j]) + helper(i,k,arr,dp) + helper(k+1,j,arr,dp);
        mini = min(mini,cost);
    }
    
    return dp[i][j] = mini;
}


int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N+1,vector<int>(N+1,0));
    int i = 1, j = N-1;
    return helper2(i,j,arr,dp);
}
