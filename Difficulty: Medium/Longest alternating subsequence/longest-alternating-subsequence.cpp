//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n=arr.size();
        if(n==1) return 1;
        if(n==2){
            if(arr[0]==arr[1]) return 1;
            return 2;
        }
          int cnt=0;
          int previous=arr[0];
          for(int i=1;i<n-1;i++){
              if((previous<arr[i] && arr[i]>arr[i+1]) || (previous>arr[i] && arr[i]<arr[i+1])){
                  cnt++;
                  previous=arr[i];
              }
          }
          return cnt+2;
    }
};












//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends