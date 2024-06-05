//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long sum=accumulate(a,a+n,(long long)0),value=0,ans=0;
        for(long long i=0;i<n;i++){
            value+=(i*a[i]);
        }
        ans=value;
        for(long long i=n-1;i>0;i--){
            value=value+sum-(long long)n*a[i];
            ans=max(ans,value);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends