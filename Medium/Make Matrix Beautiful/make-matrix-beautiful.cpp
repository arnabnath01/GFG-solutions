//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long 
class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > m, int n)
    {
        vector<ll>val(n,0);
        ll need =0;
        for(int i=0;i<n;i++)
        {
            
            ll colsum=0;
            ll rowsum=0;
            for(int j=0;j<n;j++){
                colsum+=m[i][j];
                rowsum+=m[j][i];
            }
            need = max({need, colsum,rowsum});
            val[i]=rowsum;
            
        }
        ll ans=0;
        
        for(auto x:val){
            ans+=need-x;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends