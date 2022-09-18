// https://leetcode.com/problems/course-schedule/

// finding if there is a cycle in a directed graph

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void dfs(bool* ans, unordered_set<int>& stack, unordered_multimap<int, int>& map, int i, vector<vector<int>>& prerequisites) {
    stack.insert(i);
    while (map.find(i) != map.end()) {
      auto it = map.find(i);
      auto x = map.find(i)->second;
      map.erase(it);
      if (stack.find(x) != stack.end()) {
        *ans = false;
      } else {
        dfs(ans, stack, map, x, prerequisites);
      }
    }
    stack.erase(i);
  }
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_multimap<int, int> map;
    unordered_set<int> stack;
    for (int i = 0; i < prerequisites.size(); i++) {
      map.insert({prerequisites[i][0], prerequisites[i][1]});
    }
    bool ans = true;
    for (int i = 0; i < numCourses; i++) {
      dfs(&ans, stack, map, i, prerequisites);
    }
    return ans;
  }
};