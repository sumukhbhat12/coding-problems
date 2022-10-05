#include<bits/stdc++.h>

bool cycleCheckBFS(vector<vector<int>> &adj, queue<pair<int,int>> &queue, vector<int> &visited);
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    queue<pair<int,int>> queue;
    vector<vector<int>> adj(n+1,vector<int>());
    vector<int> visited(n+1,0);
    
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            queue.push({i,-1});
            visited[i] = 1;
            if(cycleCheckBFS(adj,queue,visited)){
                return "Yes";
            }
        }
    }
    return "No";
    
}

bool cycleCheckBFS(vector<vector<int>> &adj, queue<pair<int,int>> &queue, vector<int> &visited){
    while(!queue.empty()){
        pair<int,int> temp = queue.front();
        queue.pop();
        for(auto it : adj[temp.first]){
            if(it != temp.second){
                if(!visited[it]){
                    queue.push({it,temp.first});
                    visited[it] = 1;
                }
                else{
                    return true;
                }
            }
        }
    }
    return false;
}


