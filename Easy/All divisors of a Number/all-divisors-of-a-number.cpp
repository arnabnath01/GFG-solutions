//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        if(n==1)
        {
            cout<<1<<" ";
            return ;
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0){
             pq.push(i);
             if(n/i!=i)
             pq.push(n/i);
            }
            
        }
        
        if(pq.size()==1) pq.push(n);
        while(!pq.empty())
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends