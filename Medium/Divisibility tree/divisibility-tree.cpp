//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
int ans;
int dfs(unordered_map<int,vector<int>>& g,int i,int par)
{
    int c=0;
    for(auto& x:g[i])
    {
        if(x!=par)
        {
            int k=dfs(g,x,i);
            if(k%2==0)
                ans++;
            else
                c=c+k;
        }
    }
    c++;
    return c;
}
    int minimumEdgeRemove(int n, vector<vector<int>>e)
    {
        unordered_map<int,vector<int>> g;
        for(int i=0;i<e.size();i++)
        {
           g[e[i][0]-1].push_back(e[i][1]-1);
           g[e[i][1]-1].push_back(e[i][0]-1);
        }
        ans=0;
        dfs(g,0,-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends