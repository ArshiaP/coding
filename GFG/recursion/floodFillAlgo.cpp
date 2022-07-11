//https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> image(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> image[i][j];
  }
  int sr, sc, newColor;
  cin >> sr >> sc >> newColor;
  Solution obj;
  vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
  for (auto i : ans) {
    for (auto j : i)
      cout << j << " ";
    cout << "\n";
  }
  return 0;
}  // } Driver Code Ends