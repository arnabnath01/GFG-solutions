//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>positive,negetive;
        for(auto x:arr){
            if(x<0)
            negetive.push_back(x);
            else
            positive.push_back(x);
        }
        int n=positive.size();
        int m=negetive.size();
        int i=0,j=0,ind=0;
        bool flag=1;
        while(i<n && j<m){
            if(flag){
                arr[ind++]=positive[i++];
                flag=0;
                
            }if(!flag){
                arr[ind++]=negetive[j++];
                flag=1;
            }
        }
        while(j<m){
            arr[ind++]=negetive[j++];
        }
        while(i<n){
            arr[ind++]=positive[i++];
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends