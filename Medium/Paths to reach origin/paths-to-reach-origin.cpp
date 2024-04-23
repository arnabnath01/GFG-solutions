//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
int MOD = 1000000007;
    // MEMOIZATION
    // int fun(int x , int y, vector<vector<int>> &dp){
    //     if(x==0 && y==0) return 1;
        
    //     if(x<0 || y<0) return 0;
        
    //     if(dp[x][y]!=-1) return dp[x][y];
        
    //     int left = fun(x-1,y,dp)%MOD;
    //     int up = fun(x,y-1,dp)%MOD;
        
    //     return dp[x][y]=(up+left)%MOD;
    // }
    int ways(int x, int y)
    {
        //code here.
        vector<vector<int>>dp(x+1,vector<int>(y+1,0));
        // return fun(x,y,dp);
        
        //TABULATIO 
        // dp[0][0]=1;
        
        // for(int i=0;i<=x;i++){
        //     for(int j=0;j<=y;j++){
        //         if(i==0 && j==0) dp[i][j]=1;
        //         else{
        //             int left = 0;
        //             if(i-1>=0) left = dp[i-1][j]%MOD;
        //             int up =0;
        //             if(j-1>=0) up = dp[i][j-1]%MOD;
                    
        //             dp[i][j]=up%MOD+left%MOD;
        //         }
        //     }
        // }
        // return dp[x][y]%MOD;
        
        
        //SPACE OPTIMISED
        vector<int>prev(y+1,0);
        
        for(int i=0;i<=x;i++){
            vector<int>curr(y+1,0);
            for(int j=0;j<=y;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int left = 0;
                    if(i-1>=0) left = prev[j]%MOD;
                    int up =0;
                    if(j-1>=0) up = curr[j-1]%MOD;
                    
                    curr[j]=(up+left)%MOD;
                }
                
            }
            prev = curr;
        }
        
        return prev[y];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends