// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<int> visited(V);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      ans.push_back(i);
      for (int j : adj[i]) {
        if (visited[j] == 0) {
          visited[j] = 1;
          q.push(j);
        }
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
  vector<int> ans = obj.bfsOfGraph(V, adj);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
