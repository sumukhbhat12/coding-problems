
bool canColor(int i, int col, vector<vector<int>> &mat, vector<int> &color){
    for(int j=0;j<mat.size();j++){
        if(mat[i][j] == 1 && col == color[j]){
            return false;
        }
    }
    
    return true;
}


bool helper(int ind, int m, vector<vector<int>> &mat, vector<int> &color){
    int n = mat.size();
    
    if(ind == n){
        //if we color all nodes, only then we get here
        return true;
    }
    
    int ans = false;
 
        //for each color
        for(int j=0;j<m;j++){
            if(canColor(ind,j,mat,color)){
                //set the color
                color[ind] = j;
                //recurse for next node
                ans = helper(ind+1,m,mat,color);
                if(ans == true){
                    return true;
                }
                //reset the color
                color[ind] = -1;
            }
        }
    
        //if we tried all colors and still couldn't color it, then return false
        if(color[ind] == -1){
            return false;
        }
    
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> color(mat.size(),-1);
    int ans = helper(0,m,mat,color);
    
    if(ans == 1){
        return "YES";
    }
    else{
        return "NO";
    }
}
