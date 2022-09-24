//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

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
//Function to return a list containing the bottom view of the given tree.

class Complex{
    public :
    int h_dist;
    int level;
    int order;  //to keep track of which element comes last if level and h_dist are same
    Node *node;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<Complex> nodes;
        vector<int> ans;
        int level=0;
        int order=0;
        preorderTraverse(root,0,nodes,level,order);
        int sz = nodes.size();
        sort(nodes.begin(),nodes.end(),[](const Complex &a, const Complex &b){
            if(a.h_dist < b.h_dist) return true;
            if(a.h_dist > b.h_dist) return false;
            //if a.h_dist == b.h_dist sort by level
            if(a.level > b.level) return true;
            if(b.level > a.level) return false;
            //if h_dist and level are same sort by order in which they appear
            if(a.order > b.order) return true;
            if(b.order > a.order) return false;
        });
    
        int i=1;
        //int n = nodes.size();
        int j = nodes[0].h_dist;
        int l = nodes[0].level;
        ans.push_back(nodes[0].node->data);
        while(i<sz){
            if(nodes[i].h_dist == j){
                    i++;
            }
            else{
                ans.push_back(nodes[i].node->data);
                j = nodes[i].h_dist;
                i++;
            }
        }
        
        return ans;
    }
    
    void preorderTraverse(Node *root, int dist, vector<Complex> &nodes, int level,int &order){
        if(root){
            Complex temp;
            temp.h_dist = dist;
            temp.level = level;
            temp.order = order;
            temp.node = root;
            nodes.push_back(temp);
            order++;
            preorderTraverse(root->left, dist - 1, nodes, level+1,order);
            preorderTraverse(root->right, dist + 1, nodes, level+1,order);
            
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends
