//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++



class DisJointSet{

public:
vector<int> parent,rank,size;
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
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);    // path compression
    }



    void Rank(int u,int v){
        int up=find(u);
        int vp=find(v);
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
        int up=find(u);
        int vp=find(v);
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


class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisJointSet ds(V);
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1){
                    ds.Size(i,j);
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i) cnt++;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends