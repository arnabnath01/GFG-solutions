//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		int binarySearch(int arr[],int s,int e,int x){
		    while(s>e) return -1;
		    int mid = s+(e-s)/2;
		    
		    if(arr[mid]==x) return mid;
		    
		    else if(arr[mid]>x)return binarySearch(arr,s,mid-1,x);
		    
		  return binarySearch(arr,mid+1,e,x);
		}
	int count(int arr[], int n, int x) {
	    // code here
	    int count = 0;
	    
	    int index = binarySearch(arr,0,n-1,x);
	    int index2= index-1;
	    
	    while(index<n && arr[index++]==x) {count++;}
	    while(index2>=0 && arr[index2--]==x) {count++;}
	    
	    return count;
	   
	  
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends