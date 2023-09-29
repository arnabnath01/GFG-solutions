//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
 void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return;
        
        // Mark the visited land cell
        grid[i][j] = 0;
        
        dfs(grid, i+1, j); // Down
        dfs(grid, i-1, j); // Up
        dfs(grid, i, j+1); // Right
        dfs(grid, i, j-1); // Left
    }
  
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        // Mark land cells connected to top and bottom borders
        for(int j=0; j < m; j++) {
            if(grid[0][j] == 1) dfs(grid, 0, j);
            if(grid[n-1][j] == 1) dfs(grid, n-1, j);
        }
        
        // Mark land cells connected to left and right borders
        for(int i=0; i < n; i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0);
            if(grid[i][m-1] == 1) dfs(grid, i, m-1);
        }
        
        // Count the unmarked (enclave) land cells
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
                if(grid[i][j] == 1) count++;
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends