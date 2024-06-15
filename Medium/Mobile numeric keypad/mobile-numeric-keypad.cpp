//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long long func(int n,vector<vector<int>>arr,vector<vector<vector<long long>>>&dp,int r,int c)
  {
      if(r<0||c<0||r>3||c>2)return 0;
      if(arr[r][c]==-1)return 0;
      if(n==0)return 1;
      if(dp[n][r][c]!=-1) return dp[n][r][c];
      int delrow[4]={-1,0,1,0};
      int delcol[4]={0,1,0,-1};
      long long sides=0,self=0;
      self=func(n-1,arr,dp,r,c);
      for(int i=0;i<4;i++)
      {
          sides=sides+func(n-1,arr,dp,r+delrow[i],c+delcol[i]);
      }
      dp[n][r][c]=self+sides;
      return dp[n][r][c];
  }
    long long getCount(int n) {
        // Your code goes here
        vector<vector<int>>arr(4,vector<int>(3,0));
        int id=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                arr[i][j]=id;
                id++;
            }
        }
        arr[3][0]=-1;
        arr[3][2]=-1;
        vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(4,vector<long long>(3,-1)));
        long long ans=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
               ans=ans+ func(n-1,arr,dp,i,j);
            }
        }
       
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends