//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        // Sort the array to have a better understanding of elements' distribution.
        sort(arr, arr + n);
        
        // Initialize the minimum difference to the difference between the last and the first element.
        int minDifference = arr[n - 1] - arr[0]; 
        
        // Iterate through the array elements.
        for (int i = 1; i < n; i++) {
            // Calculate the maximum possible value for the current partition from the second half.
            int maxSecondHalf = max(arr[i - 1] + k, arr[n - 1] - k);
            
            // Calculate the minimum possible value for the current partition from the first half.
            int minFirstHalf = min(arr[0] + k, arr[i] - k);
            
            // Check if the minimum for the first half is negative, meaning the partition does not exist.
            // In such cases, skip this partition.
            if (minFirstHalf < 0) 
                continue;
            
            // Update the minimum difference if the difference between the maximum of the second half
            // and the minimum of the first half is smaller.
            minDifference = min(minDifference, maxSecondHalf - minFirstHalf);
        }
        
        // Return the minimum difference found.
        return minDifference;
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