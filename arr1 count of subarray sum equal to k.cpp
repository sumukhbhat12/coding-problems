class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //mapping from prefix sum at index i to the frequency of the prefix sum from 0 to i
        //since negative elements are allowed, we may get same prefix sum again and again
        unordered_map<int,int> map;
        
        //psum tracks the prefix sum from i=0 to j, where j is the current element index
        int psum = 0, count = 0;
        int n = nums.size();
        //without map[0]=1, we will miss a single array count
        map[0] = 1;
        for(int i=0;i<n;i++){
            psum += nums[i];
            int temp = psum - k;
            //if prefix sum - target is already in map, then add frequency of (prefixsum - target) to the count
            if(map.find(temp) != map.end()){
                count += map[temp];
            }
            //increase the frequency of prefix sum by 1
            temp = map[psum];
            map[psum] = temp+1;
        }
        
        return count;
    }
};
