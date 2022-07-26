// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void dfs(int i, vector<int> adj[], vector<int>& visited, bool* ans, int prev) {
    visited[i] = 1;
    for (int j = 0; j < adj[i].size(); j++) {
      if (visited[adj[i][j]] == 0) {
        dfs(adj[i][j], adj, visited, ans, i);
      } else if (visited[adj[i][j]] == 1 and adj[i][j] != prev) {
        *ans = true;
      }
    }
  }

  bool isCycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    bool ans = false;
    int prev = 0;
    for (int i = 0; i < V; i++) {
      if (!visited[i] and !ans) {
        prev = -1;
        dfs(i, adj, visited, &ans, prev);
      }
    }
    return ans;
  }
};

int main() {
  int V, E;
  cin >> V >> E;
  vector<int> adj[V];
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  Solution obj;
  bool ans = obj.isCycle(V, adj);
  if (ans)
    cout << "1\n";
  else
    cout << "0\n";

  return 0;
}
