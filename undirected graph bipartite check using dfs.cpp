class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        int n = graph.size();
        int col = 0;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = col;
                if(!dfs(i,graph,color,!col)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(int vertex, vector<vector<int>>& graph, vector<int> &color, int col){
        for(auto it : graph[vertex]){
            if(color[it] == -1){
                color[it] = col;
                if(!dfs(it,graph,color,!col)){
                    return false;
                }
            }
            else{
                if(color[it] == color[vertex]){
                    return false;
                }
            }
        }
        return true;
    }
};
