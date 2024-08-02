//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int maxi=INT_MIN;
        int secMax=INT_MIN;
        
        
        for (int i = 0; i < n; i++) {
        if (arr[i] > maxi) {
            secMax = maxi;  // Update secMax before updating maxi
            maxi = arr[i];
        } else if (arr[i] > secMax && arr[i] != maxi) {
            secMax = arr[i];
        }
    }
        
        
        return (secMax==INT_MIN)?-1:secMax;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends