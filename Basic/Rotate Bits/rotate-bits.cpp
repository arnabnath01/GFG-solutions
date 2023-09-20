//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{


 private:
        int rotateLeftBit (unsigned int n, int d){
            if(d > 8){
                n = rotateLeftBit(n, 8);
                return rotateLeftBit(n, d - 8);
            }else{
                return (((n << d) << 16) >> 16) | (n >> (16 - d));
            }
        }
        int rotateRightBit (unsigned int n, int d){
            if(d > 8){
                n = rotateRightBit(n, 8);
                return rotateRightBit(n, d - 8);
            }else{
                return n >> d | (((n << (16 - d)) << 16) >> 16);
            }
        }
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            return {rotateLeftBit(n,d), rotateRightBit(n,d)};
        }


};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends