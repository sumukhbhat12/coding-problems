class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1){
            return false;
        }
        
        int n = stones.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        return helper2(1,1,n-1,stones,dp);
    }
    
    //TOPDOWN APPROACH
    bool helper(int i, int k, int n, vector<int>& stones, vector<vector<int>> &dp){
        if(i == n){
            return true;
        }
        
        if(i > n){
            return false;
        }
        
        if(k == 0){
            return false;
        }
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        
        bool kth = false, kplus1th = false, kminus1th = false;
        
        
        for(int j = i+1;j<=n;j++){
            
            
            if(stones[j] == stones[i] + k){
                
                kth = helper(j,k,n,stones,dp);
            }
            
            if(stones[j] == stones[i] + (k - 1)){
                
                kminus1th = helper(j,k-1,n,stones,dp);
            }
            
            if(stones[j] == stones[i] + (k + 1)){
                
                kplus1th = helper(j,k+1,n,stones,dp);
            }
            
            if(kth or kplus1th or kminus1th){
                    return true;
            }
            
        }
        
        return dp[i][k] = kth or kplus1th or kminus1th;
    }
    
    //BOTTOMUP APPROACH GIVES TLE
    //BECAUSE ITERATING NxN times is not efficient, BUT NOT SURE HOW TO OPTIMIZE THE 2ND FOR LOOP AND THE 3RD FOR LOOP
    bool helper2(int i, int k, int n, vector<int>& stones, vector<vector<int>> &dp){
        for(int j=0;j<=n;j++){
            dp[n][j] = 1;
        }
        
        for(int i=n-1;i>=1;i--){
            for(int p=n;p>=1;p--){
                bool kth = false, kplus1th = false, kminus1th = false;
        
        
                for(int j = i+1;j<=n;j++){


                    if(stones[j] == stones[i] + p){

                        kth = dp[j][p];
                    }

                    if(stones[j] == stones[i] + (p - 1)){

                        kminus1th = dp[j][p-1];
                    }

                    if(stones[j] == stones[i] + (p + 1)){

                        kplus1th = dp[j][p+1];
                    }

                    if(kth or kplus1th or kminus1th){
                            dp[i][p] = 1;
                    }

                }

                dp[i][p] = kth or kplus1th or kminus1th;
            }
        }
         
        return dp[i][k];
    }
    
};
