class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        
        int n = candidates.size();
        
        helper(n-1,target,candidates,temp,ans);
        
        return ans;
    }
    
    void helper(int n, int t, vector<int>& candidates, vector<int> &temp, vector<vector<int>> &ans){
        
        if(t == 0){
            ans.push_back(temp);
            return;
        }
        
        if(n < 0 || t < 0){
            return;
        }
    
        for(int i=n;i>=0;i--){
            if(i!=n && candidates[i] == candidates[i+1]){
                continue;
            }
            temp.push_back(candidates[i]);
            helper(i-1,t-candidates[i],candidates,temp,ans);
            temp.pop_back();
        }
    }
    
    
};
