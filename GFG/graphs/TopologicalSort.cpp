// https://practice.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // Function to return list containing vertices in Topological order.
  void dfs(int v, vector<int> &ans, vector<int> adj[], vector<bool> &marked) {
    marked[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
      if (!marked[adj[v][i]]) {
        dfs(adj[v][i], ans, adj, marked);
      }
    }
    ans.push_back(v);
  }
  vector<int> topoSort(int v, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> marked(v, 0);
    for (int i = 0; i < v; i++) {
      if (!marked[i]) {
        dfs(i, ans, adj, marked);
      }
    }
    reverse(ans.begin(),ans.end());
    return ans;
  }
};

int check(int V, vector<int> &res, vector<int> adj[]) {
  if (V != res.size())
    return 0;

  vector<int> map(V, -1);
  for (int i = 0; i < V; i++) {
    map[res[i]] = i;
  }
  for (int i = 0; i < V; i++) {
    for (int v : adj[i]) {
      if (map[i] > map[v]) return 0;
    }
  }
  return 1;
}

int main() {
  int N, E;
  cin >> E >> N;
  int u, v;

  vector<int> adj[N];

  for (int i = 0; i < E; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
  }

  Solution obj;
  vector<int> res = obj.topoSort(N, adj);

  cout << check(N, res, adj) << endl;

  return 0;
}  // } Driver Code Ends