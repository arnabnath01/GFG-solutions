//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{

public:
	int search(string pat, string txt) {
	    // code here
	    int n = txt.length();
	    int k = pat.length();
	    int i=0,j=0;
	    int cnt=0,ans=0;
	    
	    unordered_map<char,int>mp;
	    
	    for(auto c:pat)
	    {
	        mp[c]++;
            if(mp[c]==1) 
            cnt++;
	    }
	    

        // // ptint map
        // cout<<"starting"<<endl;
        // for(auto x:mp)
        // {
        //     cout<<x.first<<" "<<x.second<<endl;
        // }   

	    while(j<n)
	    {
	        // calculation
            mp[txt[j]]--;

        if(mp[txt[j]]==0)
            cnt--;  


            // sliding
	        if(j-i+1<k)
	            j++;

	       else if(j-i+1==k)
	       {
	           mp[txt[i]]++;

           
            if(cnt==0)
                ans++;

           // 
         if(mp[txt[i]]==1)
                cnt++;


	           i++,j++;
	       }

	    }
        return ans;
	}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends