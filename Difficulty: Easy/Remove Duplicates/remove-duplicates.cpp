//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        int freq[26]={0};
        for(auto x:str){
            freq[x-'a']++;
        }
        string s="";
        for(auto x:str){
            if(freq[x-'a']>=1){
                s+=x;
                freq[x-'a']=0;
            }
        }
        return s;
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
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends