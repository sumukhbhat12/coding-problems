class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int m = 9, n = 9;
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '.'){
                    ans = helper(i,j,board);
                }
            }
        }
        
    }
    
    bool helper(int i, int j, vector<vector<char>>& board){
        
        if(i == 9){
            return true;
        }
        
        if(board[i][j] != '.'){
            int temp = 0;
            if(j+1 == 9){
                temp = helper(i+1,0,board);
            }
            else{
                temp = helper(i,j+1,board);
            }
            return temp;
        }
        
        
        //foreach value from 1-9 check
        for(int a=1;a<=9;a++){
            //set value
            board[i][j] = a + '0';
            int temp=0;
            //check for validity
            if(isValid(a,i,j,board)){
                //is correct, hence recurse for future values
                if(j+1 == 9){
                    temp = helper(i+1,0,board);
                }
                else{
                    temp = helper(i,j+1,board);
                }
                
                //since it is correct, then return with the state changed
                if(temp){
                    return true;
                }
                else{
                    board[i][j] = '.';
                }
                
            }
            else{
                //incorrect, then reset to empty
                board[i][j] = '.';
            }
                
        }
        //if we tried all 1 to 9 and still couldn't get, then the board needs to backtrack and try other valid values
        if(board[i][j] == '.'){
            return false;
        }
        //just as default
        return true;
    }
    
    bool isValid(int val, int i, int j, vector<vector<char>>& board){
        // if i,j = 5,5 then 5%3 = 2 and 5-2 = 3, which is the start of that 3x3 block
        int m = i%3, n = j%3;
        int r = i-m;
        int c = j-n;
        
        //rowise and columnwise check
        for(int p=0;p<9;p++){
            //not the value we just inserted at jth column
            if(p != j){
                if(board[i][p] == val + '0'){
                    return false;
                }
            }
            
            //not the value we just inserted at ith row
            if(p != i){
                if(board[p][j] == val + '0'){
                    return false;
                }
            }
        }
        
        //3x3 block check
        for(int p=r;p<r+3;p++){
            for(int q=c;q<c+3;q++){
                if(p == i && q == j){
                    continue;
                }
                else{
                    if(board[p][q] == val + '0'){
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
};
