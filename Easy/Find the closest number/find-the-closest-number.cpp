//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{ 
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        
        int lb = lower_bound(arr,arr+n,k)-arr;
        
        if(arr[lb]==k) return k;
        
        if(lb>0){
            if (k - arr[lb - 1] < arr[lb] - k) return arr[lb - 1];
            else return arr[lb];
        }
        else return arr[lb];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends