// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void shortest_distance(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        for (int k = 0; k < matrix.size(); k++) {
          if (j == i or k == i or matrix[i][k] == -1 or matrix[j][i] == -1) {
            continue;
          } else {
            if (matrix[j][k] == -1) {
              matrix[j][k] = matrix[i][k] + matrix[j][i];
            } else {
              matrix[j][k] = min(matrix[j][k], matrix[i][k] + matrix[j][i]);
            }
          }
        }
      }
    }
  }
};

//{ Driver Code Starts.
int main() {
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }
  Solution obj;
  obj.shortest_distance(matrix);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends