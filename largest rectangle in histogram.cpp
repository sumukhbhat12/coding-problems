class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> stack;
        //monotone stack using, one pass.
        //this is the efficient version of monotone stack using 2 vectors to store left lesser and right lesser elements
        //here while popping, we calculate the answer for all the elements because, we get to access the right smaller
        //and the left smaller elements then and there, insteading of storing them separately
        //watch striver's largest rectangle in histogram part 1 and part 2 to understand
        for(int i=0;i<=n;i++){
            
            while(!stack.empty() && (i==n || heights[stack.top()]> heights[i])){
                
                int temp = stack.top();
                stack.pop();
                
                if(!stack.empty()){
                    ans = max(ans, (i-stack.top()-1)*heights[temp]);
                }
                else{
                    ans = max(ans,i*heights[temp]);
                }
            }
            stack.push(i);
        }
        
         return ans;       
    }
    
    //BRUTE FORCE GIVES TLE
    //88/98 cases
    int temp(vector<int>& heights){
        int maxarea = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            int mini = heights[i];
            int area = heights[i];
            for(int j=i;j<n;j++){
                mini = min(mini,heights[j]);
                area = (j-i+1)*mini;
                maxarea = max(area,maxarea);
            }
        }
        
        return maxarea;
    }
};
