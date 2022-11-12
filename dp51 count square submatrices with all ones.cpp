class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        
        int ans = 0;
        
        //BOTTOMUP APPROACH
        /*
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 || j == 0){
                    //first row and first column elements can atmost be the size of 1
                    //hence copy the original values
                    dp[i][j] = matrix[i][j];
                    ans += dp[i][j];
                }
                else{ 
                    if(matrix[i][j] == 1){
                        dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                        ans += dp[i][j];
                    }
                }
            }
        }
        */
        
        //SPACE OPTIMIZATION O(N)
        vector<int> prev(n+1,0), cur(n+1,0);
        
        for(int i=0;i<n;i++){
            prev[i] = matrix[0][i];
            ans += prev[i];
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j == 0){
                    cur[j] = matrix[i][j];
                    ans += cur[0];
                }
                else{ 
                    if(matrix[i][j] == 1){
                        cur[j] = 1 + min({cur[j-1], prev[j], prev[j-1]});
                        ans += cur[j];
                    }
                    else{
                        //THIS IS REQUIRED HERE BECAUSE UNLIKE IN 2D DP, 
                        //HERE CUR[J] WILL JUST HAVE THE PREV ITERATION'S VALUE INSTEAD OF DEFAULT VALUE OF 0
                        cur[j] = 0;
                    }
                }
            }
            prev = cur;
        }
        
        
        return ans;
    }
};
