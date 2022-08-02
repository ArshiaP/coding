// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // asu code
  int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int> visited(V, 0);
    int min = INT16_MAX;
    int v1 = 0;
    int v2 = 0;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        if (adj[i][j][1] < min) {
          min = adj[i][j][1];
          v1 = i;
          v2 = adj[i][j][0];
        }
      }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = min;
    visited[v1] = 1;
    visited[v2] = 1;
    for (auto x : adj[v1]) {
      if (!visited[x[0]]) {
        pq.push({x[1], x[0]});
      }
    }
    for (auto x : adj[v2]) {
      if (!visited[x[0]]) {
        pq.push({x[1], x[0]});  // weight,vertex
      }
    }
    for (int i = 0; i < V - 2; i++) {
      auto x = pq.top();
      pq.pop();
      if (!visited[x.second]) {
        ans += x.first;
        visited[x.second] = 1;
        for (auto y : adj[x.second]) {
          if (!visited[y[0]]) {
            pq.push({y[1], y[0]});
          }
        }
      } else {
        i--;
      }
    }
    return ans;
  }

  // shreyu code
  int spanningTree(int v, vector<vector<int>> adj[]) {
    vector<bool> visited(v, 0);
    int min = INT_MAX;
    int v1 = 0;
    int v2 = 0;
    for (int i = 0; i < v; i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        if (adj[i][j][1] < min) {
          min = adj[i][j][1];
          v1 = i;
          v2 = adj[i][j][0];
        }
      }
    }
    visited[v1] = 1;
    visited[v2] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < adj[v1].size(); i++) {
      if (!visited[adj[v1][i][0]]) {
        pq.push({adj[v1][i][1], adj[v1][i][0]});
      }
    }
    for (int i = 0; i < adj[v2].size(); i++) {
      if (!visited[adj[v2][i][0]]) {
        pq.push({adj[v2][i][1], adj[v2][i][0]});
      }
    }

    int ans = min;
    int count = 1;

    while (count != v - 1) {
      auto ele = pq.top();
      pq.pop();
      if (!visited[ele.second]) {
        ans = ans + ele.first;
        visited[ele.second] = 1;
        for (int i = 0; i < adj[ele.second].size(); i++) {
          if (!visited[adj[ele.second][i][0]]) {
            pq.push({adj[ele.second][i][1], adj[ele.second][i][0]});
          }
        }
        count++;
      }
    }

    return ans;
  }
};

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

  // for (int i = 0; i < V; i++) {
  //   cout << i << " : ";
  //   for (auto x : adj[i]) {
  //     cout << "{" << x[0] << " , " << x[1] << " }"
  //          << "   ";
  //   }
  //   cout << endl;
  // }

  Solution obj;
  cout << obj.spanningTree(V, adj) << "\n";

  return 0;
}

// } Driver Code Ends
