//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    static bool cmp(pair<int, int>a1, pair<int, int>a2){
        if(a1.first==a2.first){return a1.second>a2.second;}
        return a1.first<a2.first;
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<pair<int, int>>pq;
        vector<int>ans;
        for(auto &b: arr){
            if(b==x){continue;}
            int xx=abs(b-x);
            pq.push_back({xx,b});
        }
        sort(pq.begin(), pq.end(), cmp);
        for(int i=0; i<k; i++){
            int x=pq[i].second;
            ans.push_back(x);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends