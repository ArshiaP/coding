// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // Function to return max value that can be put in knapsack of capacity W.
  int knapSack(int cap, int wt[], int val[], int n) {
    vector<vector<int>> vec(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < cap + 1; j++) {
        if (wt[i-1] > j) {
          vec[i][j] = vec[i - 1][j];
        } else {
          vec[i][j] = max(vec[i - 1][j], vec[i - 1][j - wt[i-1]] + val[i-1]);
        }
      }
    }

    return vec[n][cap];
  }
};

//{ Driver Code Starts.

int main() {
  int n, w;
  cin >> n >> w;

  int val[n];
  int wt[n];

  // inserting the values
  for (int i = 0; i < n; i++)
    cin >> val[i];

  // inserting the weights
  for (int i = 0; i < n; i++)
    cin >> wt[i];
  Solution ob;
  // calling method knapSack()
  cout << ob.knapSack(w, wt, val, n) << endl;
  return 0;
}
// } Driver Code Ends