//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


using ll=long long;
class Solution
{
	public:
	    long long myPow(ll x, ll n, ll mod) {
            if (n == 0)
                return 1;
            if (n < 0)
                return 1 / myPow(x, -n, mod); 
            if (n % 2 == 1)
                return (x * myPow(x, n - 1,mod)) % mod;
            ll temp = myPow(x * x % mod, n / 2,mod) % mod;
            return (temp + mod) % mod;
	    }
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    return myPow(x,n,M);
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends