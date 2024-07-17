//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends






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
    int findUPar(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findUPar(parent[u]);    // path compression
    }



    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);
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


        void unionBySize(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);
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









class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adjNode=it[0];
                int wt=it[1];
                int node =i;
                v.push_back({wt,{node,adjNode}});
            }
            
        }
        
        sort(v.begin(),v.end());
        DisJointSet ds(V);
        int mst=0;
        for(auto it:v){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mst+=wt;
                ds.unionBySize(u,v);
            }
            
        }
        
        return mst;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends