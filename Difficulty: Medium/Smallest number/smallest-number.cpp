//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   string smallestNumber(int s, int d) {
    if (d == 1 && s > 9) return "-1";
    if (d == 1 && s <= 9) {
        return to_string(s);
    }
    
    if (s > 9 * d) return "-1";
    
    vector<int> arr(d, 0);
    
    int i = d - 1;
    
    while (s > 9 && i > 0) {
        arr[i--] = 9;
        s -= 9;
    }
    arr[i] = s;
    
    if (arr[0] == 0) {
        arr[0] = 1;
        for (int j = 1; j < d; j++) {
            if (arr[j] > 0) {
                arr[j]--;
                break;
            }
        }
    }
    
    string ans = "";
    for (auto x : arr) {
        ans += to_string(x);
    }
    return ans;
}
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends