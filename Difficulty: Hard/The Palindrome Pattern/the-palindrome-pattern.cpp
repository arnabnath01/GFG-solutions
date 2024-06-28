//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
           string ans;
    int n = arr.size();
    
    // ROW
    for(int i = 0; i < n; i++) {
        bool flag = true;
        int s = 0;
        int e = arr[i].size() - 1;
        
        while(s < e && flag) {
            if(arr[i][s] != arr[i][e])
                flag = false;
            s++;
            e--;
        }
        
        if(flag) {
            ans += to_string(i) + " R";
            break;
        }
    }
    
    if(ans.size()) return ans;
    
    int m = arr[0].size();
    // COLUMN
    for(int j = 0; j < m; j++) {
        bool flag = true;
        int s = 0;
        int e = arr.size() - 1;
        
        while(s < e && flag) {
            if(arr[s][j] != arr[e][j])
                flag = false;
            s++;
            e--;
        }
        
        if(flag) {
            ans += to_string(j) + " C";
            break;
        }
    }
    
    if(ans.size()==0) return "-1";
    
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends