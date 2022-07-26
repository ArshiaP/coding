// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  void dfs(int i, vector<int> adj[], vector<int>& visited, bool* ans, vector<bool>& recStack) {
    visited[i] = 1;
    recStack[i] = 1;
    for (int j = 0; j < adj[i].size(); j++) {
      if (visited[adj[i][j]] == 0) {
        dfs(adj[i][j], adj, visited, ans, recStack);
      } else if (recStack[adj[i][j]]) {
        *ans = true;
        return;
      }
    }
    recStack[i] = 0;
  }
  // Function to detect cycle in a directed graph.
  bool isCyclic(int V, vector<int> adj[]) {
    bool ans;
    vector<int> visited(V);
    vector<bool> recStack(V, 0);
    for (int i = 0; i < V; i++) {
      if (!visited[i] and !ans) {
        dfs(i, adj, visited, &ans, recStack);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int V, E;
  cin >> V >> E;

  vector<int> adj[V];

  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  Solution obj;
  cout << obj.isCyclic(V, adj) << "\n";

  return 0;
}

// } Driver Code Ends