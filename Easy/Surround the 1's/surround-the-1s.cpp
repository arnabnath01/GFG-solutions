//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

   class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int count=0,n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {   
                int c=0;
                if(matrix[i][j]==1)
                {
                    if(i+1<n and matrix[i+1][j]==0) c++;
                    if(j+1<m and matrix[i][j+1]==0) c++;
                    if(i-1>=0 and matrix[i-1][j]==0) c++;
                    if(j-1>=0 and matrix[i][j-1]==0) c++;
                    if(i-1>=0 and j-1>=0 and matrix[i-1][j-1]==0) c++;
                    if(i-1>=0 and j+1<m and matrix[i-1][j+1]==0) c++;
                    if(i+1<n and j-1>=0 and matrix[i+1][j-1]==0) c++;
                    if(i+1<n and j+1<m and matrix[i+1][j+1]==0) c++;
                    if(c%2==0 and c!=0) count++;
                    
                }
            }
        }
        return count;
    }
    
    
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends