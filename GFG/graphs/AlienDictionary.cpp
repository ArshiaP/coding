// https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void topo(int i, vector<int> &visited, vector<int> adj[], string &ans) {
    visited[i] = 1;
    for (int j = 0; j < adj[i].size(); j++) {
      if (!visited[adj[i][j]]) {
        topo(adj[i][j], visited, adj, ans);
      }
    }
    ans.push_back(i + 'a');
  }
  int charToVertex(char c) {
    return (c - 'a');
  }
  string findOrder(string dict[], int n, int k) {
    vector<int> adj[k];
    for (int i = 1; i < n; i++) {
      string one = dict[i - 1];
      string two = dict[i];
      int a = min(one.size(), two.size());
      int j = 0;
      while (j < a and one[j] == two[j]) j++;
      if(j==a) continue;
      adj[charToVertex(one[j])].push_back(charToVertex(two[j]));
    }
    vector<int> visited(k, 0);
    string ans = "";
    for (int i = 0; i < k; i++) {
      if (!visited[i]) {
        topo(i, visited, adj, ans);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
  int p1 = 0;
  int p2 = 0;
  for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
    p1 = order.find(a[i]);
    p2 = order.find(b[i]);
  }

  if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

  return p1 < p2;
}

// Driver program to test above functions
int main() {
  int N, K;
  cin >> N >> K;
  string dict[N];
  for (int i = 0; i < N; i++) cin >> dict[i];

  Solution obj;
  string ans = obj.findOrder(dict, N, K);
  order = "";
  for (int i = 0; i < ans.size(); i++) order += ans[i];

  string temp[N];
  std::copy(dict, dict + N, temp);
  sort(temp, temp + N, f);

  bool f = true;
  for (int i = 0; i < N; i++)
    if (dict[i] != temp[i]) f = false;

  if (f)
    cout << 1;
  else
    cout << 0;
  cout << endl;

  return 0;
}

// } Driver Code Ends