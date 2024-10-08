//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n=nums.size();
        // vector<long long>prefix(n,1);
        // prefix[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]*nums[i-1]
        // }
        
        long long mult=1;
        int zeroes=0;
        for(auto x:nums){
            if(x==0) zeroes++;
            if(x)
            mult*=x;
        }
        vector<long long>ans(n,1);
        
        for(int i=0;i<n;i++){
            
            if(zeroes && nums[i])
            ans[i]=0;
            else if(zeroes==1 && nums[i]==0){
                ans[i]=mult;
            }
            else if(zeroes>1 && nums[i]==0) ans[i]=0;
            else
           ans[i]=mult/nums[i];
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends