//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
      bool check(int i , int j, vector<vector<int>> &board, int n){
        for(int k = 0; k < j; k++){
            if(board[i][k]){
                return false;
            }
        }
        int a = i;
        int b = j;
        while(a >= 0 && b >= 0){
            if(board[a][b]){
                return false;
            }
            a--;
            b--;
        }
        a = i;
        b = j;
        while(a < n && b >= 0){
            if(board[a][b]){
                return false;
            }
            a++;
            b--;
        }
        return true;
    }
    
    void travel(int i, int n, vector<vector<int>> &board, vector<int> &curr, vector<vector<int>> &ans){
        if(i == n){
            ans.push_back(curr);
            return;
        }
        for(int j = 0; j < n; j++){
            if(check(j, i, board, n)){
                board[j][i] = 1;
                curr.push_back(j + 1);
                travel(i + 1, n, board, curr, ans);
                board[j][i] = 0;
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<vector<int>> board (n, vector<int> (n, 0));
        travel(0, n, board, curr, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends