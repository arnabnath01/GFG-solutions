//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
   bool Solve(string &wild, string &pattern, int i, int j){
        
        if(i >= wild.length() && j >= pattern.length()){
            return true;
        }
        
        if(i >= wild.length() && j < pattern.length()){
            return false;
        }
        
        // if pattern string ended but wild not so check if the remaining string is "*"
        // But if it is not "*" but a word then return false
        // And we will not check for "?" because it can only insert character not empty space
        
        if(i < wild.length() && j >= pattern.length()){
            for(int k = i; k< wild.length(); k++){
                if(wild[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(wild[i] == pattern[j] || wild[i] == '?'){
            return Solve(wild, pattern, i+1, j+1);
        }
        // either insert sequence so "i" or notinsert any sequence but empty string so move i+1
        else if(wild[i] == '*'){
            bool insert = Solve(wild, pattern, i, j+1);
            bool notInsert = Solve(wild, pattern, i+1, j);
            return insert || notInsert;
        }
        else{
            return false;
        }
    }
    bool match(string wild, string pattern)
    {
        int i = 0;
        int j = 0;
        return Solve(wild, pattern, i, j);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends