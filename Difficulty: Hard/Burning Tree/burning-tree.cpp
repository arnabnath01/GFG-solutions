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
  public:
  
  int findDistance(Node* target, map<Node*,Node*>&vis){
     
     queue<Node*>q;
     int cnt=0;
     unordered_map<Node*,int>mp;
     mp[target]=1;
     q.push(target);
     
     while(!q.empty()){
         int sz=q.size();
         int flag=0;
         for(int i=0;i<sz;i++){
            Node* node=q.front();   
            q.pop();
            
            if(vis[node] && !mp[vis[node]]){
                mp[vis[node]]=1;
                q.push(vis[node]);
                flag=1;
            }
            if(node->left && !mp[node->left]){
                mp[node->left]=1;
                q.push(node->left);
                flag=1;
            }
            if(node->right && !mp[node->right]){
                mp[node->right]=1;
                 q.push(node->right);
                flag=1;
            }
         }
         if(flag) cnt++;
     }
     return cnt;
  }
  
  
  Node* locateTarget(Node* root, map<Node*,Node*>&vis, int target){
      Node* curr;
      queue<Node*>q;
      q.push(root);

      while(!q.empty()){
          Node* node=q.front();
          q.pop();
          if(node->data==target){
              curr=node;
          }
           if(node->left){
              q.push(node->left);
              vis[node->left]=node;
          }
           if(node->right){
              q.push(node->right);
              vis[node->right]=node;
          } 
      }
      
      return curr;
  }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
         map<Node*,Node*>vis;
         Node* tarNode=locateTarget(root,vis,target);
         int dist=findDistance(tarNode,vis);
         
        return dist;
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