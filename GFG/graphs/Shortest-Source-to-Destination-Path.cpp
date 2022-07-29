// https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int row;
  int col;
  bool isValid(int i, int j, vector<vector<int>>& visited) {
    return (i >= 0 and i < row) and (j >= 0 and j < col) and !visited[i][j];
  }
  int shortestDistance(int n, int m, vector<vector<int>> a, int x, int y) {
    if (a[0][0] == 0 or a[x][y] == 0) {
      return -1;
    }
    if (x == 0 and y == 0) {
      return 0;
    }
    row = n;
    col = m;
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    q.push({0, 0});
    q.push({-1, -1});
    int ans = 1;
    visited[0][0] = 1;
    while (!q.empty()) {
      auto ele = q.front();
      q.pop();
      if (ele.first == -1 and !q.empty()) {
        q.push({-1, -1});
        ans++;
      } else {
        for (int i = 0; i < 4; i++) {
          if (ele.first + r[i] == x and ele.second + c[i] == y) {
            return ans;
          } else if (isValid(ele.first + r[i], ele.second + c[i], visited) and a[ele.first + r[i]][ele.second + c[i]]) {
            visited[ele.first + r[i]][ele.second + c[i]] = 1;
            q.push({ele.first + r[i], ele.second + c[i]});
          }
        }
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.
int main() {
  int N, M, x, y;
  vector<vector<int>> v(3, vector<int>(4));
  v = {{1, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 1}};
  Solution ob;
  cout << ob.shortestDistance(3, 4, v, 0, 3) << "\n";
  // cout<<ob.isValid(0,1)<<endl;
}
// } Driver Code Ends