#include <bits/stdc++.h> 
void bfs(int i, int vertex, vector<vector<int>> &adj, vector<int> &ans, vector<int> &visited, queue<int> &queue);
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    vector<int> visited(vertex,0);
    vector<vector<int>> adj(vertex,vector<int>());
    queue<int> queue;
    for(int i=0;i<edges.size();i++){
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    //without sorting every adjacency list, coding ninjas gives error
    for(int i=0;i<vertex;i++){
        sort(adj[i].begin(),adj[i].end());
    }
    
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            queue.push(i);
            visited[i] = 1;
            bfs(i,vertex,adj,ans,visited,queue);
        }
    }
    return ans;
}

void bfs(int i, int vertex, vector<vector<int>> &adj, vector<int> &ans, vector<int> &visited, queue<int> &queue){
    while(!queue.empty()){
        ans.push_back(i);
        for(int j=0;j<adj[i].size();j++){
            if(!visited[adj[i][j]]){
                queue.push(adj[i][j]);
                visited[adj[i][j]] = 1;
            }
        }
        queue.pop();
        i = queue.front();
        
    }
}
