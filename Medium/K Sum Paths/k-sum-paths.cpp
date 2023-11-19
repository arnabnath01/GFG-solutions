//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
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
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  private:
  
    const int mod = 1e9+7;
    void solve(Node* root, int k, unordered_map<int, int>& sumCnt, int sum, int& cnt){
        if(root == NULL){
            return;
        }
        
        // add current nodes data to sum and modify the map count
        sum += root -> data;
        
        // calculate cnt
        // if suppose k = 20 and current sum is 13, then if there exists a sum of 7 
        // already in map we can increase count
        cnt += sumCnt[sum - k] % mod;
        
        // store the current sum to map
        sumCnt[sum]+=1 % mod;
        
        
        // if current sum is equal to target sum
        if(sum == k){
            cnt+=1 % mod;
        }
        
        // recursively call left and right
        solve(root -> left, k, sumCnt, sum, cnt);
        solve(root -> right, k, sumCnt, sum, cnt);
        
        // remove current sum count from map
        sumCnt[sum]--;
        
    }
    
  public:
    int sumK(Node *root,int k)
    {
        int cnt = 0;
        unordered_map<int, int> sumCnt;
        int sum = 0;
        //sumCnt[0] = 1;
        
        solve(root, k, sumCnt, sum, cnt);
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends