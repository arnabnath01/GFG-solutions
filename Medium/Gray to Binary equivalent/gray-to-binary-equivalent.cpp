//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    string decimalToBinary(int n) {
        if(n==0) return "0";
        string res="";
        while(n>0) {
            int b=n%2;
            res+=(char)(b+48);
            n/=2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string binaryToGray(string n) {
        string res="";
        res+=n[0];
        for(int i=1; i<n.size(); i++) {
            int x=(int)(n[i]-'0');
            int y=(int)(res[i-1]-'0');
            int z=x^y;
            res+=(char)(z+48);
        }
        return res;
    }
    int binaryToDecimal(string n) {
        int sz=n.size(), b=1, dec=0;
        for(int i=sz-1; i>=0; i--) {
            char ch=n[i];
            int x=(int)(ch-'0');
            dec+=x*b;
            b*=2;
        }
        return dec;
    }
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        // Your code here
        string bin=decimalToBinary(n);
        string gray=binaryToGray(bin);
        int num=binaryToDecimal(gray);
        return num;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends