// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int n;
  int m;
  bool isValid(int i, int j) {
    return (i >= 0 and i < n) and (j >= 0 and j < m);
  }
  // Function to find the number of islands.
  int numIslands(vector<vector<char>>& grid) {
    queue<pair<int, int>> q;
    int count = 0;
    n = grid.size();
    m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int i = 0;
    int j = 0;
    int size = m * n;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (grid[i][j] == '1' and !visited[i][j]) {
          visited[i][j] = 1;
          q.push({i, j});

          while (!q.empty()) {
            auto a = q.front().first;
            auto b = q.front().second;
            q.pop();
            if (isValid(a - 1, b - 1) and !visited[a - 1][b - 1] and grid[a - 1][b - 1] == '1') {
              q.push({a - 1, b - 1});
              visited[a - 1][b - 1] = 1;
            }
            if (isValid(a - 1, b) and !visited[a - 1][b] and grid[a - 1][b] == '1') {
              q.push({a - 1, b});
              visited[a - 1][b] = 1;
            }
            if (isValid(a - 1, b + 1) and !visited[a - 1][b + 1] and grid[a - 1][b + 1] == '1') {
              q.push({a - 1, b + 1});
              visited[a - 1][b + 1] = 1;
            }
            if (isValid(a, b - 1) and !visited[a][b - 1] and grid[a][b - 1] == '1') {
              q.push({a, b - 1});
              visited[a][b - 1] = 1;
            }
            if (isValid(a, b + 1) and !visited[a][b + 1] and grid[a][b + 1] == '1') {
              q.push({a, b + 1});
              visited[a][b + 1] = 1;
            }
            if (isValid(a + 1, b - 1) and !visited[a + 1][b - 1] and grid[a + 1][b - 1] == '1') {
              q.push({a + 1, b - 1});
              visited[a + 1][b - 1] = 1;
            }
            if (isValid(a + 1, b) and !visited[a + 1][b] and grid[a + 1][b] == '1') {
              q.push({a + 1, b});
              visited[a + 1][b] = 1;
            }
            if (isValid(a + 1, b + 1) and !visited[a + 1][b + 1] and grid[a + 1][b + 1] == '1') {
              q.push({a + 1, b + 1});
              visited[a + 1][b + 1] = 1;
            }
          }
          count++;
        }
      }
    }
    return count;
  }
}

;

//{ Driver Code Starts.
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m, '#'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  Solution obj;
  int ans = obj.numIslands(grid);
  cout << ans << '\n';

  return 0;
}
// } Driver Code Ends