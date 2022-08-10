// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to find length of longest increasing subsequence.
  int longestSubsequence(int n, int a[]) {
    vector<int> ans (n,0);
    int largest;
    for(int i = 0; i< n ; i++){
      largest = 0;
      for(int j = 0; j< i ; j++){
        if(a[j]<a[i] && ans[j]>largest){
          largest = ans[j];
        }
      }
      ans[i] = largest +1;
    }
    largest = 0;
    for(int i=0;i<n;i++){
      if(ans[i]>largest){
        largest = ans[i];
      }
    }
    return largest;
  }
};

//{ Driver Code Starts.
int main() {
  // taking total testcases
  int n;

  // taking size of array
  cin >> n;
  int a[n];

  // inserting elements to the array
  for (int i = 0; i < n; i++)
    cin >> a[i];
  Solution ob;
  // calling method longestSubsequence()
  cout << ob.longestSubsequence(n, a) << endl;
}

// } Driver Code Ends