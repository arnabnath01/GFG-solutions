//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int n=str1.size();
        string ans="";
        string pr="";
        int c1=0;
        int c2=0;
        for(int i=2;i<n;i++){
            ans+=str1[i];
        }
        for(int i=0;i<n-2;i++){
            pr+=str1[i];
        }
        ans+=str1[0];
        ans+=str1[1];
        pr=str1[n-1]+pr;
        pr=str1[n-2]+pr;
        for(int i=0;i<n;i++){
            if(ans[i]==str2[i])
            {
                c1++;
            }
            if(pr[i]==str2[i]){
                c2++;
            }
        }if(c1==n || c2==n){
            return true;
        }return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends