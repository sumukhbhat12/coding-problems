#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    //KAHN's ALGORITHM
    vector<vector<int>> adj(v,vector<int>());
    vector<int> indegree(v,0);
    vector<int> ans;
    queue<int> queue;
    
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        //get indegree for all vertices
        indegree[edges[i][1]]++;
    }
    
    //output indegree for testing
    /*
    for(auto it:indegree){
        cout<<it<<" ";
    }
    */
    
    //push to the queue vertices whose indegree is 0
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            queue.push(i);
        }
    }
    
    while(!queue.empty()){
        int temp = queue.front();
        queue.pop();
        ans.push_back(temp);
        
        //for each vertex in the queue add it to ans vector, decrement its adjacent vertices' indegree by 1
        //if the adjacent vertex's indegree becomes 0, add that vertex to the queue
        for(auto it : adj[temp]){
            indegree[it]--;
            if(indegree[it] == 0){
                queue.push(it);
            }
        }
    }
    
    return ans;
}
