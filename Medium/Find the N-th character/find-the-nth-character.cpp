//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
  public:
   void solve(string &s, string &str, int r, int n){
      if(r == 0) return;
      str = "";
     for(int i = 0;i <= n;i++){
        if(s[i] == '0')
        str += "01";
        else
        str += "10";
     }
     s = str;
     solve(s, str, r - 1, n);
     return;
    }
    char nthCharacter(string s, int r, int n) {
        //code here
        string str = "";
        solve(s, str, r, n);
        // cout<<str<<endl;
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends