class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        helper(n-1,target,candidates,temp,ans);
        return ans;
    }
    
    void helper(int n, int t, vector<int>& candidates, vector<int> &temp, vector<vector<int>> &ans){
        if(n < 0 || t < 0){
            return;
        }
        if(t == 0){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(candidates[n]);
        helper(n,t-candidates[n],candidates,temp,ans);
        temp.pop_back();
        helper(n-1,t,candidates,temp,ans);
    }
};
