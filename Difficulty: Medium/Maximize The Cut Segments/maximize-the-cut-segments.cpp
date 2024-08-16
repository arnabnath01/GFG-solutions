//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    
    int dp[10001];
    int solve(int ind,int x,int y,int z){
        if(ind==0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=INT_MIN;
        if(ind-x>=0) ans= max(ans,1+solve(ind-x,x,y,z));
        if(ind-z>=0) ans= max(ans,1+solve(ind-z,x,y,z));
        if(ind-y>=0) ans= max(ans,1+solve(ind-y,x,y,z));
        return dp[ind]=ans;
    }
    
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {   
        memset(dp,-1,sizeof(dp));
        solve(n,x,y,z);
        return dp[n]<0? 0:dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends