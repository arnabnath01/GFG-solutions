//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        
        int n = s.length();
        vector<int> dp(n, 0);
        
        stack<pair<char,int>> st;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            
            if(s[i] == '(') {
                st.push({'(', cnt});
                cnt++;
            }
            else {
                
                if(!st.empty()) {
                    pair<char,int> pt = st.top();
                    if(!st.empty() && pt.first == '(') {
                        dp[pt.second] = 2;
                        st.pop();
                    }
                    else {
                        cnt++;
                    }
                }
                else {
                    cnt++;
                }
                
            }
        }
        
        int ans = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += dp[i];
            ans = max(ans, sum);
            
            if(dp[i] == 0) {
                sum = 0;
            }
 
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends