//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int maxWater = 0 , n = arr.size() ;
        int low = 0 , high = n - 1 ;
        
        while(low < high) {
            int currWater = min(arr[low] , arr[high]) * (high - low) ;
            maxWater = max(maxWater , currWater) ;
            if(arr[low] < arr[high]) ++low ;
            else --high ;
        }
        
        return maxWater ;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends