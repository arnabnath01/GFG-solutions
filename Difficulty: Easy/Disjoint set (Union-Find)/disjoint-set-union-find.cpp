//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int x);
void unionSet(int a[],int x ,int z);
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
			a[i]=i;
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			if(s=="UNION"){
				int z,x;
				cin>>x>>z;
				unionSet(a,x,z);
			}
			else{
				int x;
				cin>>x;
				int parent=find(a,x);
				cout<<parent<<" ";
			}
		}
		cout<<endl;
	}
}
// } Driver Code Ends


/*Complete the functions below*/
int find(int A[],int x)
{
       //add code here
       
       if(A[x]==x)
       return x;
       return A[x]=find(A,A[x]);
       
}
void unionSet(int parent[],int u,int v)
{
	int up=find(parent,u);
        int vp=find(parent,v);
        if(up==vp) return ;
        
        parent[up]=vp;
        
        
}