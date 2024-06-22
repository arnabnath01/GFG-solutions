//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int MOD = 1e9+7;

    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int tot=accumulate(arr.begin(),arr.end(),0);
        
  
        if(tot<d || (tot-d)%2) return 0;
        
        int s2=(tot-d)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,0));
        // return f(n-1,d,s2,arr,dp);
        if(arr[0]==0)  dp[0][0]=2;
        else dp[0][0]=1;
        
        // for(int i=1;i<n;i++){
        //     dp[i][0]++;
        // }
        
        if(arr[0]!=0 && arr[0]<=s2) dp[0][arr[0]]=1;
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=s2;target++){
                
                int nontake = dp[ind-1][target];
                  int take=0;
                  if(arr[ind]<=target)
                  take = dp[ind-1][target-arr[ind]];
                  dp[ind][target]=(take+nontake)%MOD;
            }
        }
        
        return dp[n-1][s2];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends