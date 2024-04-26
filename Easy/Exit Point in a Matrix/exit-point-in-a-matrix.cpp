//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<int>ans = {-1,-1};
        int i=0,j=0;
        char dir = 'R';
        while(i>=0 && i<n && j>=0 && j<m){
            ans[0]=i;
            ans[1]=j;
            if(matrix[i][j]){
                matrix[i][j]=0;
                if(dir=='R'){
                    dir='D';
                    i++;
                }
                else if(dir=='D'){
                    dir='L';
                    j--;
                }
                else if(dir=='L'){
                    dir='U';
                    i--;
                }
                else{
                    dir='R';
                    j++;
                }
            }
            else{
                if(dir=='R'){
                    j++;
                }
                else if(dir=='D'){
                    i++;
                }
                else if(dir=='L'){
                    j--;
                }
                else{
                    i--;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends