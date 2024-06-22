//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        string brackets;
        vector<int>ans;
        for(auto c:str)
        {
            if(c=='(' || c==')')
            brackets+=c;
        }
        
        stack<pair<char,int>>st;
        
        int cnt =0;
        //  (())()  1 2 2 1 3 3
        for(auto x:brackets){
            if(x=='('){
                cnt++;
                st.push({x,cnt});
                ans.push_back(cnt);;
            }
            else{

                if(st.empty()){
                    ans.push_back(++cnt);
                }
                int tmp=st.top().second;
                ans.push_back(tmp);
                st.pop();
            }

    // cout<<"cnt: "<<cnt<<endl;
    //         for(auto x:ans)
    //         cout<<x<<" ";
    //         cout<<endl;

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
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends