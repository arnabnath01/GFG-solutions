//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjls[V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] != 0 && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        int v[V] = {0};
        int c = 0;
        for (int i = 0; i < V; i++) {
            if (v[i] != 1) {
                c++;
                dfs(i, v, adjls);
            }
        }
        return c;
    }
    
private:
    void dfs(int node, int v[], vector<int> adjls[]) {
        v[node] = 1;
        for (auto it : adjls[node]) {
            if (v[it] != 1) {
                dfs(it, v, adjls);
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends