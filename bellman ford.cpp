//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> distance(V,100000000);
        distance[S] = 0;
        
        //relax all edges n-1 times
        for(int i=0;i<V-1;i++){
            for(auto edge : edges){
                if(distance[edge[0]] != 100000000 && distance[edge[0]] + edge[2] < distance[edge[1]]){
                    distance[edge[1]] = distance[edge[0]] + edge[2];
                }
            }
        }
        
        //relax all edges once more to check for negative weight cycle
        int flag = 0;
        for(auto edge : edges){
            long temp = distance[edge[1]];
            if(distance[edge[0]] != 100000000 && distance[edge[0]] + edge[2] < distance[edge[1]]){
                    distance[edge[1]] = distance[edge[0]] + edge[2];
            }
            if(temp != distance[edge[1]]){
                flag = 1;
                break;
            }
        }
        
        if(flag == 1){
           
            return {-1};
        }
        return distance;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
