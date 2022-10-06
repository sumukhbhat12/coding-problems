class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        int n = graph.size();
        queue<int> queue;
        int col = 0;
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = col;
                queue.push(i);
                if(!bfs(graph,color,col,queue)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool bfs(vector<vector<int>>& graph, vector<int> &color, int col, queue<int> &queue){
        while(!queue.empty()){
            int temp = queue.front();
            col = !color[temp];
            queue.pop();
            for(auto it : graph[temp]){
                if(color[it] == -1){
                    color[it] = col;
                    queue.push(it);
                }
                else{
                    if(color[it] == color[temp]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
