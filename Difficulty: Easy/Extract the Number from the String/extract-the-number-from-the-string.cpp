//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sen) {
        int no=0;
        long long tmp=0;
        long long maxi = INT_MIN;
        vector<long long> ans;
        
        for(int i=0; i<sen.size(); i++){
            if(sen[i]>='0' && sen[i]<='9'){
                if(sen[i]=='9') no = 1;
                else tmp = tmp*10 + (sen[i]-'0');
                // cout<<tmp<<" ";
            }
            else{
                if(tmp!=0 && no!=1) ans.push_back(tmp);
                tmp=0;
                no=0;
            }
        }
        if(tmp!=0 && no!=1) ans.push_back(tmp);
        // for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
        if(ans.empty() || ans[0]==0) return -1;
        for(int i=0; i<ans.size(); i++){
            maxi = max(ans[i], maxi);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends