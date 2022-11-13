class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<int> markedcol(n,0);
        
        helper(0,n,temp,ans,markedcol);
        return ans;
    }
    
    void helper(int r, int n, vector<string> &temp, vector<vector<string>> &ans, vector<int> &markedcol){
        
        if(r == n){
            ans.push_back(temp);
            return;
        }
        
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            
            //if markedcol is 1 then it means the column already contains a queen above. 
            if(markedcol[i] != 1){
                if(isValid(i,n,temp)){
                    
                    //if the queen placement is valid, then change dot to Q, push the string to temp
                    //and mark the column as 1
                    s[i] = 'Q';
                    temp.push_back(s);
                    markedcol[i] = 1;
                    
                    //recurse for the next row
                    helper(r+1,n,temp,ans,markedcol);
                    
                    //now after the recursion, if we got the answer, then it will be present in ans
                    //if we get or don't get, we still have to continue the recursion for other placements
                    //hence undo the current placement
                    s[i] = '.';
                    temp.pop_back();
                    markedcol[i] = 0;
                }
            }
        }
    }
    
    
    bool isValid(int i, int n, vector<string> &temp){
        if(temp.empty()){
            return true;
        }
        
        int m = temp.size();
        int k = i;
        
        //Here, just checking the previous row is not enough, since there is a chance of some queen 2 or 3 rows above
        //diagonally attacking th current row queen
        //the case of queen directly above is handled by the markedcol array
        
        //left diagonal
        for(int j=m-1;j>=0 && k-1 >= 0;j--){
            string s = temp[j];
            
            if(s[k-1] == 'Q'){
                return false;
            }
            k--;
        }
        
        k = i;
        //right diagonal
        for(int j=m-1;j>=0 && k+1 < n;j--){
            string s = temp[j];
            
            if(s[k+1] == 'Q'){
                return false;
            }
            k++;
        }
        
        return true;
    }
    
};
