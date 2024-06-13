//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  const int MOD=1e9+7;
    int padovanSequence(int n) {
        // code here.
        
        vector<int>seq(n+1,0);
        seq[0]=seq[1]=seq[2]=1;
        
        for(int i=3;i<=n;i++){
            seq[i]=seq[i-2]%MOD+seq[i-3]%MOD;
        }
        return seq[n]%MOD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends