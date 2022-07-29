// https://practice.geeksforgeeks.org/problems/minimum-cost-path3833/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int row;
  int col;
  bool isValid(int i, int j, vector<vector<int>>& visited) {
    return (i >= 0 and i < row) and (j >= 0 and j < col) and !visited[i][j];
  }
  int minimumCostPath(vector<vector<int>>& grid) {
    vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    multimap<int, pair<int, int>> map;
    row = grid.size();
    col = grid[0].size();
    cost[0][0] = grid[0][0];
    map.insert({cost[0][0], {0, 0}});
    for (int i = 0; i < grid.size() * grid.size() - 1; i++) {
      if (map.empty()) continue;
      auto ele = map.begin();
      map.erase(map.begin());
      int c = ele->first;
      int x = ele->second.first;
      int y = ele->second.second;
      visited[x][y] = 1;
      if (isValid(x - 1, y, visited) and cost[x - 1][y] > c + grid[x - 1][y]) {
        cost[x - 1][y] = c + grid[x - 1][y];
        map.insert({cost[x - 1][y], {x - 1, y}});
      }
      if (isValid(x + 1, y, visited) and cost[x + 1][y] > c + grid[x + 1][y]) {
        cost[x + 1][y] = c + grid[x + 1][y];
        map.insert({cost[x + 1][y], {x + 1, y}});
      }
      if (isValid(x, y - 1, visited) and cost[x][y - 1] > c + grid[x][y - 1]) {
        cost[x][y - 1] = c + grid[x][y - 1];
        map.insert({cost[x][y - 1], {x, y - 1}});
      }
      if (isValid(x, y + 1, visited) and cost[x][y + 1] > c + grid[x][y + 1]) {
        cost[x][y + 1] = c + grid[x][y + 1];
        map.insert({cost[x][y + 1], {x, y + 1}});
      }
    }
    return cost[row - 1][col - 1];
  }
};

//{ Driver Code Starts.
int main() {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  Solution obj;
  int ans = obj.minimumCostPath(grid);
  cout << ans << "\n";

  return 0;
}
// } Driver Code Ends