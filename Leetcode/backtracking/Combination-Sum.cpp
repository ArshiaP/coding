// https://leetcode.com/problems/combination-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void recur(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> curr, int index) {
    if (target == 0) {
      ans.push_back(curr);
    }
    for (int i = index; i < candidates.size(); i++) {
      if (target >= candidates[i]) {
        curr.push_back(candidates[i]);
        recur(candidates, target - candidates[i], ans, curr, i);
        curr.pop_back();
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> curr;
    recur(candidates, target, ans, curr, 0);
    return ans;
  }
};

int main() {
  vector<int> candidates{2, 3, 6, 7};
  Solution s;
  vector<vector<int>> ans = s.combinationSum(candidates, 7);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}