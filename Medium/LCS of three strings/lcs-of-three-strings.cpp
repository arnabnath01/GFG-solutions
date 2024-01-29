//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    // int longestCommonSubsequence(string s1, string s2)
    //     {
    //     int n = s1.size(),m=s2.size();       
    //         vector<int> curr(m+1,0),prev(m+1,0);
    //         for(int i1=1;i1<=n;i1++)
    //         {
    //             for(int i2=1;i2<=m;i2++)
    //             {
    //                 if(s1[i1-1]==s2[i2-1])
    //                 curr[i2] = 1 + prev[i2-1];

    //                 else{       // when does not match 
    //                         curr[i2]= 0+max(prev[i2],curr[i2-1]);
    //                 }

    //             }

    //             prev = curr;
    //         }

    //         return prev[m];
    //     }
        
        
    public:

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            int dp[n1+1][n2+1][n3+1];
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n1;i++)
            {
                for(int j=1;j<=n2;j++)
                {
                    for(int k=1;k<=n3;k++)
                    {
                        if(A[i-1]==B[j-1] && B[j-1]==C[k-1])
                            dp[i][j][k]=1+dp[i-1][j-1][k-1];
                        else
                         dp[i][j][k]=max(dp[i][j-1][k],max(dp[i-1][j][k],dp[i][j][k-1]));
                    }
                }
            }
            
            return dp[n1][n2][n3];
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends