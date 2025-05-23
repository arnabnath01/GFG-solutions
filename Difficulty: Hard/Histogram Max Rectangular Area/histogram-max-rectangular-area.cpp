//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
            stack<int> st;
        int maxArea = 0;
        int n = arr.size(); 

        for (int i = 0; i < n; i++) {
           while (!st.empty() && arr[st.top()] > arr[i]) {
            int element = st.top();
            st.pop();
            int x = i;   // x is Next smallest element and y is previous smallest element
            int y = st.empty() ? -1 : st.top();
            maxArea = max(arr[element] * (x - y - 1), maxArea);
         }
        st.push(i);
     }

      while (!st.empty()) {
        int element = st.top();
        st.pop();
        int x = n;
        int y = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, (x - y- 1) * arr[element]);
    }

    return maxArea;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends