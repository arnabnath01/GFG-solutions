//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
   vector<int> matrixDiagonally(vector<vector<int>>&mat){
        int n=mat.size();
        vector<int>diagonal;
        bool clk=1;
            for(int i=0;i<2*n-1;i++){
                int j,k;
                if(i<n)j=0;
                else j= i-n+1;
                k=i-j;
                if(clk){
                    if(i<n)k=0;
                    else k=i-n+1;
                    j=i-k;
                }
                while(k<n && j<n && k>=0 && j>=0){
                    diagonal.push_back(mat[j][k]);
                    if(clk){j--;k++;}
                    else   {k--;j++;}
                }
                clk=clk^1;
            }
        return diagonal;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends