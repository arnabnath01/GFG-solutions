//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }

  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({start[i],end[i]});
        }
        sort(p.begin(),p.end(),cmp);
        int cnt=1;
        
        int time=p[0].second;
        for(int i=1;i<n;++i){
            if(p[i].first>time)
            {
                cnt++;
                time=p[i].second;
            }
            
            
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends