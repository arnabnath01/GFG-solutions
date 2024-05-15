//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        int cnt=0,temp=N,ans;
        while(temp!=0){
            int bits=temp&1;
            if(bits==1) cnt++;
            else if(bits==0) break;
            temp>>=1;
        }
        ans=N|(1<<cnt);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends