//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  bool isPrime(int n){
      if(n<=3) return 1;
      for(int i=2;i<=sqrt(n);i++){
          if(n%i==0) return 0;
      }
      return 1;
  }
    vector<int> getPrimes(int n) {
        // code here
        int i=2;
        vector<int>ans;
        while(i<=n/2){
            if(isPrime(i) && isPrime(n-i))
            {
                ans.push_back(i);
                ans.push_back(n-i);
                break;
            }
            i++;
        }
        
        if(ans.size()==0) return {-1,-1};
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends