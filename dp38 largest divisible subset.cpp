class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //sort it to make sure that as you select the next element, if it is divisible with the current element
        //then it is automatically divisible with the previous elements
        sort(nums.begin(),nums.end());
        return helper(nums);
    }
    
    
    //TO UNDERSTAND THIS APPROACH, WATCH STRIVER'S PRINTING LONGEST INCREASING SUBSEQUENCE DP42 LECTURE
    vector<int> helper(vector<int> &nums){
        vector<int> ans;
        
        int n = nums.size();
        
        //longest holds the longest length of divisible subsets from 0 to i
        //prev holds the previous index from which we got to the current index i in longest array
        //first, the longest length at each i is 1, that is the value itself.
        vector<int> longest(n,1), prev(n);
        
        for(int i=1;i<n;i++){
            //initialize prev as i for each ith index
            prev[i] = i;
            for(int j=0;j<i;j++){
                //for each i, if nums[i] and nums[j] are divisible then
                //if current value of longest is smaller than when adding jth value's longest + 1
                if((nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0) && longest[i] < longest[j] + 1){
                    longest[i] = longest[j] + 1;
                    //set prev of i as j
                    prev[i] = j;
                }
            }
        }
        
        //find the index of max value in longest array
        int maxi = -1, ind = 0;
        for(int i=0;i<n;i++){
            if(longest[i] > maxi){
                maxi = longest[i];
                ind = i;
            }
        }
        
        //backtrack through the prev array and insert all the values into the answer one by one
        ans.push_back(nums[ind]);
        while(prev[ind] != ind){
            ind = prev[ind];
            ans.push_back(nums[ind]);
        }
        
        return ans;
        
    }
};
