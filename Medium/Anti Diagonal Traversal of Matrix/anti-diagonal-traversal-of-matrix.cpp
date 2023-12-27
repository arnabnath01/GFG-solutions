//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
private:
    bool is_Valid(int x, int y, int n) 
    {
        return x>=0 && y>=0 && x<n && y<n;
    }
    
public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        int n=mat.size(), dx, dy;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!vis[i][j]) {
                    vis[i][j]=true;
                    ans.push_back(mat[i][j]);
                    
                    dx=i+1, dy=j-1;
                    while(is_Valid(dx,dy,n)) {
                        ans.push_back(mat[dx][dy]);
                        vis[dx][dy]=true;
                        dx=dx+1, dy=dy-1;
                    }
                }
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends