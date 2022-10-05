#include <bits/stdc++.h>

void dfs(int vertex, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans);
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v,vector<int>());
    vector<int> visited(v,0);
    
    //used as a stack
    vector<int> ans;
    
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    for(int i=0;i<v;i++){
        if(!visited[i]){
            visited[i] = 1;
            dfs(i,adj,visited,ans);
            ans.push_back(i);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

void dfs(int vertex, vector<vector<int>> &adj, vector<int> &visited, vector<int> &ans){
    for(auto it : adj[vertex]){
        if(!visited[it]){
            visited[it] = 1;
            dfs(it,adj,visited,ans);
            ans.push_back(it);
        }
    }
}
