//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        // int maxi= *max_element(arr,arr+n);
        // int mini= *min_element(arr,arr+n);
        
        // return maxi-mini-2*k;
        
        sort(arr,arr+n);
        int ans = arr[n-1]-arr[0]; 
        
        for(int i=1;i<n;i++)
        {
            int maxi=max(arr[i-1]+k,arr[n-1]-k);
            int mini =min(arr[0]+k,arr[i]-k);
            if(mini<0) continue;
            
            ans=min(ans,maxi-mini);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends