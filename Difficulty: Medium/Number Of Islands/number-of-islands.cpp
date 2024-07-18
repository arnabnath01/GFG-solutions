//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



class DisJointSet{

vector<int> parent,rank,size;

public:
    DisJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }

   
   // time complexity: O(4*alpha) ~ O(4) ~ O(1
    int Find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=Find(parent[u]);    // path compression
    }



    void Rank(int u,int v){
        int up=Find(u);
        int vp=Find(v);
        if(up==vp) return ;

        if(rank[up]<rank[vp]){
            parent[up]=vp;
        }
        else if(rank[up]>rank[vp]){
            parent[vp]=up;
        }
        else{   // equal rank
        parent[up]=vp;
        rank[vp]++;
        }

    }


        void Size(int u,int v){
        int up=Find(u);
        int vp=Find(v);
        if(up==vp) return ;
        
        if(size[up]<size[vp]){
            parent[up]=vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp]=up;
            size[up]+=size[vp];
        }
        
        }

};

bool isvalid(int r, int c, int n, int m){
    if(r>=0 && r<n && c>=0 && c<m)return true;
    return false;
}


class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        int  cnt=0;
        DisJointSet ds(n * m+1);
        for(auto it:operators)
        {
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int dr[]={-1,0, 0, 1};
            int dc[]={0, -1, 1, 0};
            
            for(int i=0; i<4; i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];
                if(isvalid(adjr, adjc, n, m)){
                    if(vis[adjr][adjc]==1){
                    
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if(ds.Find(nodeNo)!=ds.Find(adjNodeNo)){
                            cnt--;
                            ds.Size(nodeNo, adjNodeNo);
                        }
                        
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends