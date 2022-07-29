// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// https://www.youtube.com/watch?v=V8qIqJxCioo

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void topo(int v, stack<int> &st, vector<int> adj[], vector<bool> &marked) {
    marked[v] = 1;
    for (int i = 0; i < adj[v].size(); i++) {
      if (!marked[adj[v][i]]) {
        topo(adj[v][i], st, adj, marked);
      }
    }
    st.push(v);
  }

  void dfs(int i, vector<int> adj[], vector<bool>& visited) {
    visited[i] = 1;
    for (int j = 0; j < adj[i].size(); j++) {
      if (visited[adj[i][j]] == 0) {
        dfs(adj[i][j], adj, visited);
      }
    }
  }

  int kosaraju(int v, vector<int> adj[]) {
    vector<bool> marked(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++) {
      if (!marked[i])
        topo(i, st, adj, marked);
    }

    vector<int> trans[v];

    for(int i=0; i<v; i++){
      for(int j=0; j<adj[i].size(); j++){
        trans[adj[i][j]].push_back(i);
      }
    }

    fill(marked.begin(), marked.end(), 0);

    int ans = 0;

    while(!st.empty()){
      int i = st.top();
      st.pop();
      if(!marked[i]){
        ans++;
        dfs(i, trans, marked);
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
  }

  Solution obj;
  cout << obj.kosaraju(V, adj) << "\n";

  return 0;
}

// steps:

// 1. do topological sort

// 2. get transpose of graph

// 3. do dfs according to the topo sort order. each time you do dfs increase the count