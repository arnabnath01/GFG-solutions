//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i=0,j=0;
        int n=arr1.size(),m=arr2.size();
        int kthEl=arr1[0];
        int cnt=0;
        while(i<n&&j<m){
            if(arr1[i]>arr2[j]){
                kthEl=arr2[j];
                j++;
            }else{
                kthEl=arr1[i];
                i++;
            }
            cnt++;
            if(k==cnt){
                return kthEl;
            }
        }
        
        if(i<n){
            while(k!=cnt){
                cnt++;
                i++;
            }
            kthEl=arr1[i-1];
        }
        if(j<m){
            while(k!=cnt){
                cnt++;
                j++;
            }
            kthEl=arr2[j-1];
        }
        
        return kthEl;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends