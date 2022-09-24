//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Complex{
    public:
    int h_dist;
    int level;
    Node *node;
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<Complex> nodes;
        vector<int> ans;
        preorderTraverse(root,nodes,0,0);
        sort(nodes.begin(),nodes.end(),[](const Complex &a, const Complex &b){
            if(a.h_dist < b.h_dist) return true;
            if(a.h_dist > b.h_dist) return false;
            //if h_dist is equal then sort based on level
            if(a.level < b.level) return true;
            if(a.level > b.level) return false;
            return false;
        });
        
        ans.push_back(nodes[0].node->data);
        int i=1;
        int j = nodes[0].h_dist;
        int n = nodes.size();
        while(i < n){
            if(nodes[i].h_dist == j){
                i++;
            }
            else{
                    ans.push_back(nodes[i].node->data);
                    j = nodes[i].h_dist;
            }
        }
        
            return ans;
    }
    
    void preorderTraverse(Node *root, vector<Complex> &nodes, int h_dist, int level){
        if(root){
            Complex temp;
            temp.h_dist = h_dist;
            temp.level = level;
            temp.node = root;
            nodes.push_back(temp);
            
            preorderTraverse(root->left,nodes,h_dist-1,level+1);
            preorderTraverse(root->right,nodes,h_dist+1,level+1);
        }
    }

};



//{ Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
