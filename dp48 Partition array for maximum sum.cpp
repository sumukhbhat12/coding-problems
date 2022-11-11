class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        //vector<int> dp(n+1,0);
        //return helper2(0,n,k,arr,dp);
        return helper3(0,n,k,arr);
    }
    
    //TOPDOWN APPROACH
    int helper(int i, int n, int k, vector<int>& arr,  vector<int> &dp){
        
        if(i == n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int maxi = INT_MIN;
        int sum = 0;
        int temp;
        for(int j=i;j<i+k && j<n;j++){
            maxi = max(maxi,arr[j]);
            temp = maxi*(j-i+1) + helper(j+1,n,k,arr,dp);
            sum = max(sum,temp);
        }
        
        return dp[i] = sum;
    }
    
    //BOTTOMUP APPROACH
    int helper2(int i, int n, int k, vector<int>& arr,  vector<int> &dp){
        
       for(int i=n-1;i>=0;i--){
           
           int maxi = INT_MIN;
            int sum = 0;
            int temp;
           
            for(int j=i;j<i+k && j<n;j++){
                maxi = max(maxi,arr[j]);
                temp = maxi*(j-i+1) + dp[j+1];
                sum = max(sum,temp);
            }

            dp[i] = sum;
        }
        
        return dp[i];
    }
    
};
