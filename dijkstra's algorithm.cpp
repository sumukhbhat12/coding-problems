#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int,int>>> adj(vertices,vector<pair<int,int>>());
    
    //min heap to hold the {distance,node} pair
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pqueue;
    
    //distance vector holds the distance from the source node to all other nodes, initially
    // it is maximum
    vector<int> distance(vertices,INT_MAX);
    
    for(int i=0;i<edges;i++){
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
 
    //output the adjacency list for testing
    /*
    for(int i=0;i<vertices;i++){
        cout<<i<<" ";
        for(auto it : adj[i]){
            cout<<it.first<<","<<it.second<<" ";
        }
        cout<<"\n";
    }
    */
    
    //push the source node along with it's distance to itself that is 0, to the queue
    pqueue.push({0,source});
    distance[source] = 0;
    while(!pqueue.empty()){
        //get the node closest to the current node
        pair<int,int> temp = pqueue.top();
        pqueue.pop();
        
        //for each adjacent nodes to the current node
        for(auto it : adj[temp.second]){
            //this is required for exit condition
            int temp2 = distance[it.first];
            
            //manually update the distance to the adjacent node if it's not already minimum
            //it.first is the adjacent node, temp.second is the current node
            //it.second is the distance from the current node to the adjacent node
            distance[it.first] = min(distance[it.first], distance[temp.second] + it.second);
            
            //for stopping condition
            //if the node's value is already minimum, it doesn't need to be added to the 
            //queue again
            if(distance[it.first] != temp2)
                pqueue.push({distance[it.first],it.first});
        }
    }

    return distance;
}
