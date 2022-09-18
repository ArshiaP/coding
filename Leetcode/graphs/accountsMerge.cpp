// https://leetcode.com/problems/accounts-merge/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void dfs(unordered_set<string> &visited, unordered_map<string, vector<string>> &adj, string s, vector<string> &vec) {
    visited.insert(s);
    vec.push_back(s);
    for (int i = 0; i < adj[s].size(); i++) {
      if (visited.find(adj[s][i]) == visited.end()) {
        dfs(visited, adj, adj[s][i], vec);
      }
    }
  }
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    unordered_map<string, vector<string>> adj;
    unordered_set<string> visited;
    vector<vector<string>> ans;

    for (int i = 0; i < accounts.size(); i++) {
      for (int j = 2; j < accounts[i].size(); j++) {
        adj[accounts[i][1]].push_back(accounts[i][j]);
        adj[accounts[i][j]].push_back(accounts[i][1]);
      }
    }

    for (int i = 0; i < accounts.size(); i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        if (visited.find(accounts[i][j]) == visited.end()) {
          ans.push_back({accounts[i][0]});
          dfs(visited, adj, accounts[i][j], ans[ans.size() - 1]);
        }
      }
    }

    for (int i = 0; i < ans.size(); i++) {
      sort(++ans[i].begin(), ans[i].end());
    }

    return ans;
  }
};