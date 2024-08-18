//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

public:
    bool canSplit(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum & 1) return false;
        int n = arr.size();
        if (n == 1) return false;
        
        int target = sum / 2;
        int left = 0;
        
        for (int num : arr) {
            left += num;
            if (left == target) return true;
            if (left > target) return false;
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends