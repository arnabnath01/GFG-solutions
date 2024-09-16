//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         vector<int>temp;
         int idx1=l;
         int idx2=m+1;
         
         // while both index 1 & 2 exists
         while(idx1<=m && idx2<=r){
             if(arr[idx1]<=arr[idx2]){
                 temp.push_back(arr[idx1++]);
             }else{
                 temp.push_back(arr[idx2++]);
             }
         }
         
         // if left array still exist
         while(idx1<=m){
              temp.push_back(arr[idx1++]);
         }
          // if right array still exist
         while(idx2<=r){
              temp.push_back(arr[idx2++]);
         }
         
         
         int j=0;
         for(int i=l;i<=r;i++){
             arr[i]=temp[j++];
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code herem
        if(l>=r) return ;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends