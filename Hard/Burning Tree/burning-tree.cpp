//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    Node* findNode(Node* root, int target) {
        if (root == NULL || root->data == target)
            return root;
        Node* left = findNode(root->left, target);
        if (left)
            return left;
        return findNode(root->right, target);
    }

    void markParent(Node* root, unordered_map<Node*, Node*>& parent_check, Node* target) {
        queue<Node*> q;
        q.push(root);
        parent_check[root] = NULL;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->left) {
                parent_check[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent_check[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int maxDistance(Node* root, unordered_map<Node*, Node*>& parent_check, Node* center) {
        int maxDist = 0;
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(center);
        visited[center] = true;

        while (!q.empty()) {
            int size = q.size();
            bool burnedAny = false;
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    burnedAny = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                if (curr->right && !visited[curr->right]) {
                    burnedAny = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                if (parent_check[curr] && !visited[parent_check[curr]]) {
                    burnedAny = true;
                    visited[parent_check[curr]] = true;
                    q.push(parent_check[curr]);
                }
            }
            if (burnedAny)
                maxDist++;
        }

        return maxDist;
    }

public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent_check;
        Node* center = findNode(root, target);
        markParent(root, parent_check, center);
        return maxDistance(root, parent_check, center);
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends