//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int mod=1e9+7;
        int prev=1;
        int curr=1;
        int temp=0;
        
        for(int i=0;i<n-1;i++){
            temp=curr;
            curr=(prev+curr)%mod;
            prev=temp;
        }
        
        return prev%mod;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends