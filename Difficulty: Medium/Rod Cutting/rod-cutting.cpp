//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int cutRod(int price[], int n) {
    int target = n;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Initialize dp for the first length (1 unit rod)
    for (int j = 1; j <= target; j++) {
        dp[0][j] = j * price[0];
    }

    // Fill the dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            int notTake = dp[i-1][j];
            int take = INT_MIN;
            if (i + 1 <= j) {
                take = price[i] + dp[i][j - (i + 1)];
            }
            dp[i][j] = max(notTake, take);
        }
    }

    // Return the maximum value
    return dp[n-1][target];
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends