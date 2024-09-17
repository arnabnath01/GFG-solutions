//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTabs(vector<string> &arr) {
        // Your Code goes here.
        unordered_set<string>mp;
        for(auto x:arr){
            if(x=="END"){
                mp.clear();
            }else{
                if(mp.find(x)!=mp.end())
                mp.erase(x);
                else
                mp.insert(x);
            }
        }
        return mp.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string> arr;
        string str;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        int ans = ob.countTabs(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends