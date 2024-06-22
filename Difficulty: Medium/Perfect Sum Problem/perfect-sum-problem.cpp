//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends











class Solution {
    public:
    int mod = 1e9+7;
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
     vector<vector<int>>dp(n,vector<int>(sum+1,0));
     for (int i = 0; i < n; ++i) {
        dp[i][0] = 1; // There's always one way to make sum 0 (by picking no elements)
    }
    
    if (arr[0] <= sum) {
        dp[0][arr[0]] = 1;
    }
    if (arr[0] == 0) {
        dp[0][0] = 2; // If arr[0] is zero, we can either include it or not, hence two ways
    } else {
        dp[0][0] = 1; // If arr[0] is not zero, there's only one way to make sum 0 (by picking no elements)
    }
     for(int index=1;index<n;index++)
     {
         for(int target = 0;target<=sum;target++)
         {
            int pick=0;
            if(arr[index]<=target)
            pick = dp[index-1][target-arr[index]];
            int notPick = dp[index-1][target];
            dp[index][target]=(pick+notPick) % mod;   
         }
     }
     return   dp[n-1][sum]%mod;
    }
      
};






//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends