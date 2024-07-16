//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) {
        // Your code goes here
        // string ans="";
        int tar=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==ch){ count--;
                // tar=i;
            }
            
            if(count==0) {
                tar=i;
                break;
                
            }
        }
        // if(tar==-1) return "";
        if(count || tar==s.size()-1) return "";
        return s.substr(tar+1);
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
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends