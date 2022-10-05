class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //TOPOLOGICAL SORT
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<int> indegree(numCourses,0);
        queue<int> queue;
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                queue.push(i);
            }
        }
        
        //this count is used to check if the graph is DAG or not
        int count = 0;
        
        while(!queue.empty()){
            int temp = queue.front();
            queue.pop(); 
            count++;
            for(auto it : adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0){
                    queue.push(it);
                }
            }
        }
        //if the graph is a DAG, the count is incremented only as many times as the no. of vertices
        if(count == numCourses){
            return true;
        }
        return false;
    }
};
