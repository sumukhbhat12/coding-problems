#include<bits/stdc++.h>

bool cycleCheckDFS(int vertex, int prev, vector<vector<int>> &adj, vector<int> &visited);
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n+1,vector<int>());
    vector<int> visited(n+1,0);
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i] = 1;
            if(cycleCheckDFS(i,-1,adj,visited)){
                return "Yes";
            }
        }
    }
    return "No";
}

bool cycleCheckDFS(int vertex, int prev, vector<vector<int>> &adj, vector<int> &visited){
    for(auto it : adj[vertex]){
        if(it != prev){
            if(!visited[it]){
                visited[it] = 1;
                if(cycleCheckDFS(it,vertex,adj,visited)){
                    return true;
                }
            }
            else{
                return true;
            }
        }
    }
    return false;
}
