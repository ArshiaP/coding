// https://leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;


// will give TLE but is the correct solution
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    unordered_map<string, vector<string>> adj;

    for (auto a : wordList) {
      for (auto b : wordList) {
        int changes = 0;
        for (int i = 0; i < a.length(); i++) {
          if (a[i] != b[i]) {
            changes++;
          }
        }
        if (changes == 1) {
          adj[a].push_back(b);
        }
      }
    }

    queue<string> q;
    q.push(beginWord);
    unordered_set<string> visited;
    visited.insert(beginWord);
    int ans = 0;
    bool found = false;

    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        string s = q.front();
        q.pop();
        for (int j = 0; j < adj[s].size(); j++) {
          if (visited.find(adj[s][j]) == visited.end()) {
            if (adj[s][j] == endWord) {
              found = true;
              break;
            }
            q.push(adj[s][j]);
            visited.insert(adj[s][j]);
          }
        }
      }
      ans++;
      if (found) {
        break;
      }
    }
    return found ? ans + 1 : 0;
  }
};
