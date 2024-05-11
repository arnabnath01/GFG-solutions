//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
        vector<int> ans(n,0);
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i<n;i++){
            pq.push({arr[i],i});
        }
        
        set<int> st;
        for(auto it: arr){
            st.insert(it);
        }
        
        int cnt = st.size()==n ? pq.size() : pq.size()-(n-st.size());
        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            ans[p.second] = cnt ;
            if(p.first!=pq.top().first){
              cnt--;
            }
            
        }
        return ans ;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends