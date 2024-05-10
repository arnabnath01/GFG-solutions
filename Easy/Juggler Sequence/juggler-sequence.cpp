//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void f(int n, vector<int> &ans)
    {
        ans.push_back(n);
        if(n == 1) return;
        
        if(n%2 == 0)  f(1ll*sqrt(n),ans);
        else  f(sqrt(1ll*n*n*n),ans);
    }
public:
    vector<int> jugglerSequence(int N){
        vector<int> ans;
        f(N,ans);
        
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

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends