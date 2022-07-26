// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void dfs(int i, vector<int> adj[], vector<int>& visited, vector<int>& ans) {
    visited[i] = 1;
    ans.push_back(i);
    for (int j = 0; j < adj[i].size(); j++) {
      if (visited[adj[i][j]] == 0) {
        dfs(adj[i][j], adj, visited, ans);
      }
    }
  }

  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> visited(V);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        dfs(i, adj, visited, ans);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int tc;

  int V, E;
  cin >> V >> E;

  vector<int> adj[V];

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // string s1;
  // cin>>s1;
  Solution obj;
  vector<int> ans = obj.dfsOfGraph(V, adj);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}