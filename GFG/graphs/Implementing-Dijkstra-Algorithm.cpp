// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int findMinNode(vector<int> vec, vector<bool> visited) {
    int minIdx;
    int minimum = INT_MAX;
    for (int i = 0; i < vec.size(); i++) {
      if (!visited[i] and vec[i] < minimum) {
        minIdx = i;
        minimum = vec[i];
      }
    }
    return minIdx;
  }
  vector<int> dijkstra(int v, vector<vector<int>> adj[], int s) {
    vector<int> ans(v, INT_MAX);
    vector<bool> visited(v, 0);
    visited[s] = 1;
    for (auto vec : adj[s]) {
      ans[vec[0]] = vec[1];
    }
    ans[s] = 0;

    for (int i = 0; i < v - 1; i++) {
      int minIdx = findMinNode(ans, visited);
      visited[minIdx] = 1;
      for (auto vec : adj[minIdx]) {
        if (ans[vec[0]] > (ans[minIdx] + vec[1])) {
          ans[vec[0]] = ans[minIdx] + vec[1];
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
  vector<vector<int>> adj[V];
  int i = 0;
  while (i++ < E) {
    int u, v, w;
    cin >> u >> v >> w;
    vector<int> t1, t2;
    t1.push_back(v);
    t1.push_back(w);
    adj[u].push_back(t1);
    t2.push_back(u);
    t2.push_back(w);
    adj[v].push_back(t2);
  }
  int S;
  cin >> S;

  Solution obj;
  vector<int> res = obj.dijkstra(V, adj, S);

  for (int i = 0; i < V; i++)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}

// } Driver Code Ends