//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int i  , int n , int *arr , vector<int> &dp){
        
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];
        
        
        int take = arr[i] + solve(i+2 , n , arr , dp);
        int nontake = solve(i+1 , n , arr , dp);
        
        
        return dp[i]=  max(take , nontake);
        
    }
    int findMaxSum(int *arr, int n) {
        // code here
        vector<int> dp(n+1, -1);
        
        return solve(0 , n , arr , dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends