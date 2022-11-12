class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,0);
        return helper2(0,target,nums,n,dp);
    }
    
    //TOPDOWN APPROACH
    int helper(int i, int t, vector<int>& nums, int n, vector<int> &dp){
        
        if(t == 0)
            return 1;
        
        if(i == n || t < 0)
            return 0;
        
        if(dp[t] != -1)
            return dp[t];
        
        int count = 0;
        
        
        for(int j=0;j<n;j++){
            
            count += helper(j,t-nums[j],nums,n,dp);
            
        }
        
        return dp[t] = count;
    }
    
    
    //BOTTOMUP APPROACH
    long helper2(int i, int t, vector<int>& nums, int n, vector<int> &dp){
        dp[0] = 1;
        
        for(int i=1;i<=t;i++){
            long count = 0;
            
            for(int j=0;j<n;j++){
                if(i-nums[j] < 0){
                    count += 0;
                }
                else{
                    count += dp[i-nums[j]];
                }
            }
            
            dp[i] = count;
            
        }
        
        return dp[t];
        
    }
    
    
};
