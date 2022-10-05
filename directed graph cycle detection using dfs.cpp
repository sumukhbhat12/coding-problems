class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<int> visited(numCourses,0);
        vector<int> visited2(numCourses,0);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                visited[i] = 1;
                visited2[i] = 1;
                if(cycleCheckDFS(i,adj,visited,visited2)){
                    //cannot finish all courses since there's a cycle
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
    
    bool cycleCheckDFS(int vertex, vector<vector<int>> &adj, vector<int> &visited, vector<int> &visited2){
        for(auto it : adj[vertex]){
            if(!visited[it]){
                visited[it] = 1;
                visited2[it] = 1;
                if(cycleCheckDFS(it,adj,visited,visited2)){
                    //there is a cycle in the graph
                    return true;
                }
            }
            else
            if(visited2[it]){
                return true;
            }
        }
        visited2[vertex] = 0;
        return false;
    }
};
