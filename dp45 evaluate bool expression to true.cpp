#include <bits/stdc++.h> 

//TOPDOWN APPROACH
long long int helper(int i, int j, int isTrue, string &exp, vector<vector<vector<long long int>>> &dp){
    if(i>j)
        return 0;
    
    if(i == j)
        if(isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    
    long long int count = 0;
    for(int k=i+1;k<j;k+=2){
        //no. of left partition if true, no. of right partition if true
        //no. of left partition if false, no. of right partition if false
        
        //we need to check for false as well because for '|' we need the count of all
        //because | returns true for all T | T and T | F and F | T
        //same with ^, T | F and F | T return true
        long long int lt, rt, lf, rf;
        lt = helper(i,k-1,1,exp,dp);    //solve for left half if it returns true
        rt = helper(k+1,j,1,exp,dp);    //solve for right half if it returns true
        lf = helper(i,k-1,0,exp,dp);    //solve for left half if it returns false
        rf = helper(k+1,j,0,exp,dp);    //solve for right half if it returns false
        
        if(exp[k] == '&'){
            //if we need to return the count of trues or false
            //it is specified by isTrue variable
            if(isTrue){
                // A & B is true if A is true and B is true
                count +=  (lt * rt) % 1000000007;
            }
            else{
                //A & B is false if any one or both are false
                count +=  (lt * rf) % 1000000007 + (lf * rt) % 1000000007 + (lf * rf) % 1000000007;
            }
        }
        else
        if(exp[k] == '|'){
            if(isTrue){
                //A | B is true if any one is true
                count +=  (lt * rt) % 1000000007 + (lf * rt) % 1000000007 + (lt * rf) % 1000000007;
            }
            else{
                //A | B is false if all are false
                count += (lf * rf) % 1000000007;
            }
        }
        else{
            if(isTrue){
                // A ^ B is true if A and B are different
                count +=  (lf * rt) % 1000000007 + (lt * rf) % 1000000007;
            }
            else{
                //A ^ B is false if A and B are the same
                count += (lt * rt) % 1000000007 + (lf * rf) % 1000000007;
            }
        }
    }
    return dp[i][j][isTrue] = count % 1000000007;
}

//BOTTOMUP APPROACH
long long int helper2(int i, int j, int isTrue, string &exp, vector<vector<vector<long long int>>> &dp){
    for(int i=exp.length()-1;i>=0;i--){
        for(int j=0;j<exp.length();j++){
            for(int k=0;k<2;k++){
                if(i == j){
                    if(k)
                        dp[i][j][k] = exp[i] == 'T';
                    else
                        dp[i][j][k] = exp[i] == 'F';
                }
                else{
                    long long int count = 0;
                    for(int p=i+1;p<j;p+=2){

                        long long int lt, rt, lf, rf;
                        lt =dp[i][p-1][1];   
                        rt = dp[p+1][j][1];    
                        lf = dp[i][p-1][0];    
                        rf = dp[p+1][j][0];    

                        if(exp[p] == '&'){
                            if(k){
                                count +=  (lt * rt) % 1000000007;
                            }
                            else{
                                count +=  (lt * rf) % 1000000007 + (lf * rt) % 1000000007 + (lf * rf) % 1000000007;
                            }
                        }
                        else
                        if(exp[p] == '|'){
                            if(k){
                                count +=  (lt * rt) % 1000000007 + (lf * rt) % 1000000007 + (lt * rf) % 1000000007;
                            }
                            else{
                                count += (lf * rf) % 1000000007;
                            }
                        }
                        else{
                            if(k){
                                count +=  (lf * rt) % 1000000007 + (lt * rf) % 1000000007;
                            }
                            else{
                                count += (lt * rt) % 1000000007 + (lf * rf) % 1000000007;
                            }
                        }
                    }

                    dp[i][j][k] = count % 1000000007;
                }
           }
        }
    }
    
    return dp[i][j][isTrue];
}




int evaluateExp(string & exp) {
    // Write your code here.
    
    //helper(start,end,isTrue,exp)
    //isTrue represents whether we want true or false
    vector<vector<vector<long long int>>> dp(exp.length()+1,vector<vector<long long int>>(exp.length()+1,vector<long long int>(2,0)));
    return helper2(0,exp.length()-1,1,exp,dp);
}
