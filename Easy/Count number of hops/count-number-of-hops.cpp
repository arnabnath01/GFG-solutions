//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int long long mod = 1e9 + 7;
    long long countWays(int n)
    {
     long long int *arr = new long long int[n + 1];
       arr[0] = 1;
       arr[1] = 1;
       arr[2] = 2;
       for (int i = 3; i <= n; i++) {
      arr[i] = arr[i - 1] % mod + arr[i - 2] % mod + arr[i - 3] % mod;
     }
     return arr[n] % mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends