//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      bool check(string pattern, string str, int patPos, int strPos, vector<vector<int>>& dp){

        if(dp[patPos+1][strPos+1]!=-1){ //Same values already computed
            return dp[patPos+1][strPos+1];
        }
        //case 1. Base cases
        if(patPos < 0 and strPos >=0){ // Pattern is exhausted
            return false;
        }
        if(patPos < 0 and strPos < 0){ // Both pattern and string is exhausted
            return true;
        }
        if(patPos >=0 and strPos < 0 and pattern[patPos]!='*') { // Only string is exhausted and pattern is not *
            return false;
        }

        //case 2. str pos < 0 and remaining patStr is * 
        if(patPos >= 0 and strPos < 0 and pattern[patPos]=='*'){ 
            return dp[patPos+1][strPos+1] = check(pattern, str, patPos-1, strPos, dp);
        }
            
        //case 3: Pattern is non wild
        if(pattern[patPos]!='*' and pattern[patPos]!='?')
        {
            if(str[strPos] != pattern[patPos]){
                return false;
            }
            else{            
                return dp[patPos+1][strPos+1] = check(pattern, str, patPos-1, strPos-1, dp);
            }
        }
        //case 4: Pattern is  wild
        //case 4.1 - "?"
        if(pattern[patPos]=='?'){
            return dp[patPos+1][strPos+1] = check(pattern, str, patPos-1, strPos-1, dp);
        }            
        //case 4.2 - "*"
        return dp[patPos+1][strPos+1] =  check(pattern, str, patPos, strPos-1, dp) or
                                         check(pattern, str, patPos-1, strPos, dp);
        
        
    }
    int wildCard(string pattern, string str) {
        // code here
        vector<vector<int>> dp(pattern.size()+1, vector<int>(str.size()+1, -1) );// Initilise vector of size patternSize * stringSize
        return check(pattern, str, pattern.size()-1, str.size()-1, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends