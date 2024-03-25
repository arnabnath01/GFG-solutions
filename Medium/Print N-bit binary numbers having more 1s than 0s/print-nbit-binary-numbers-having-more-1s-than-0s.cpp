//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    
    void solve(int ind , string s,int zeroes,int ones,vector<string>&ans,int n)
    {
        if(ind==n){
            ans.push_back(s);
            return ;
        }
        
        solve(ind+1,s+"1",zeroes,ones+1,ans,n);
        
        if(zeroes<ones)
        solve(ind+1,s+"0",zeroes+1,ones,ans,n);
    }
    
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	   // int ones =ceil(n/2);
	   // int zeroes = n-ones;
	    
	    vector<string> ans;
	    string s="1";
	    
	    solve(1,s,0,1,ans,n);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends