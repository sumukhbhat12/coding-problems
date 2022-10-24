//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        //display adj matrix for testing
        /*
        for(int i=0;i<V;i++){
            for(auto node : adj[i]){
                cout<<i<<" "<<node[0]<<" "<<node[1]<<"\n";
            }
            cout<<"\n";
        }
        */
        
        typedef pair<int,pair<int,int>> P;
        // pair<int,pair<int,int>> denotes {weight, {node, parent}}
        priority_queue<P, vector<P>,greater<P>> pqueue;
        
        vector<int> visited(V,0);
        
        int sum = 0;
        
        //first node doesn't have a weight and a parent
        pqueue.push({0,{0,-1}});
        
        
        while(!pqueue.empty()){
            P temp = pqueue.top();
            pqueue.pop();
            //temp.second.first is the current node
            //after popping the node, mark it as visited and add the weight to the sum
            if(!visited[temp.second.first]){
                visited[temp.second.first] = 1;
                sum += temp.first;
            
                //push adjacent nodes to the queue only if it is unvisited
                for(auto node : adj[temp.second.first]){
                    //if adjacent node is not the parent then add it to the queue
                    if(node[0] != temp.second.second)
                        pqueue.push({node[1],{node[0],temp.second.first}});
                    
                }
            }
        }
        
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
