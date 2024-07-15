//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int MOD=1e5;
        vector<int>vis(100000,INT_MAX);
        queue<pair<int,int>>q;
        // node dist
        q.push({start,0});
        
        vis[start]=0;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();
            
            for(auto it:arr){
                int num=(node*it)%MOD;
                if(dis+1<vis[num]){
                    vis[num]=dis+1;  
                  if(num==end) return dis+1;
                  
                  q.push({num,dis+1});
                }
                
                
                
            }
        }
        
        if(start==end)return 0;
        return -1;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends