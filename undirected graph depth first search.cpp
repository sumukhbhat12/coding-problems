void dfs(int i, vector<vector<int>> &adj, vector<int> &visited, int V, vector<int> &intermediate);
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> adj(V,vector<int>());
    vector<int> visited(V,0);
    vector<vector<int>> ans;
    vector<int> intermediate;
    //convert edges matrix into an adjacency list
    for(int i=0;i<E;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    //output adjacency list
    /*
    for(int i=0;i<V;i++){
        cout<<i<<"->";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,V,intermediate);
            ans.push_back(intermediate);
            intermediate.clear();
        }
    }
    return ans;
}

void dfs(int i, vector<vector<int>> &adj, vector<int> &visited, int V, vector<int> &intermediate){
    intermediate.push_back(i);
    visited[i] = 1;
    for(int j=0;j<adj[i].size();j++){
        if(!visited[adj[i][j]]){
            dfs(adj[i][j],adj,visited,V,intermediate);
        }
    }
}
