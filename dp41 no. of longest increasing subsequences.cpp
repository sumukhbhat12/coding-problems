class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> longest(nums.size(),1), count(nums.size(),1);
        int n = nums.size();
        int maxi = 1;
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(nums[i] > nums[j] && longest[i] < longest[j] + 1){
                    longest[i] = longest[j] + 1;
                    count[i] = count[j];
                    if(longest[i] > maxi){
                        maxi = longest[i];
                    }
                    
                    
                }
                else
                if(nums[i] > nums[j] && longest[i] == longest[j] + 1){
                    count[i] += count[j];
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(longest[i] == maxi){
                ans += count[i];
            }
        }
        
        return ans;
    }
};
//
