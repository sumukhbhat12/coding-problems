class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(k,n,1,temp,ans);
        return ans;
    }
    
    void helper(int k, int n, int num, vector<int> &temp, vector<vector<int>> &ans){
        
        if(n == 0 && k == 0){
            ans.push_back(temp);
            return;
        }
        
        if(k <= 0 || n <= 0){
            return;
        }
        
        
        for(int j=num;j<=9;j++){
            temp.push_back(j);
            helper(k-1,n-j,j+1,temp,ans);
            temp.pop_back();

        }
        
    }
    
};
