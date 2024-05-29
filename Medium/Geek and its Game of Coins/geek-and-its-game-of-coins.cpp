//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
        if(n<x && n<y) return n%2;
        
        bool dp[n+1];
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            if(i-1>=0 && dp[i-1]==false)
            dp[i]=true;
            else if(i-x>=0 && !dp[i-x])
            dp[i]=true;
            else if(i-y>=0 && !dp[i-y])
            dp[i]=1;
            else dp[i]=0;
            
        }
        
        return dp[n];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends