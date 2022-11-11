class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> temp(n,0);
        int maxarea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] != '0'){
                    temp[j]++;
                }
                else{
                    temp[j] = 0;
                }
            }
            maxarea = max(maxarea, helper(temp));
            
        }
        return maxarea;
    }
    
    //this function outputs the max rectangle area using the same technique as the largest rectangle in histogram problem  
    int helper(vector<int> &histogram){
        int n = histogram.size();
        stack<int> stack;
        int area = 0;
        for(int i=0;i<=n;i++){
            while(!stack.empty() && (i == n || histogram[stack.top()] >= histogram[i])){
                int temp = histogram[stack.top()];
                stack.pop();
                int width = 0;
                
                if(!stack.empty()){
                    width = i - stack.top() - 1;
                }
                else{
                    width = i;
                }
                
                area = max(area, temp * width);
            }
            stack.push(i);
        }
        return area;
    }
    
};
