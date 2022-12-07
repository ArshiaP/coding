// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> elementsLeft;
    unordered_set<int> toDelete;

    for (int i = 0; i < nums.size(); i++) {
      elementsLeft.insert(nums[i]);
    }

    int ans = 0;

    for (auto it = elementsLeft.begin(); it != elementsLeft.end(); it++) {
      if (toDelete.find(*it) == toDelete.end()) {
        int curr = 0;
        for (int i = 0; elementsLeft.find(*it - i) != elementsLeft.end(); i++) {
          toDelete.insert(*it - i);
          curr++;
        }
        for (int i = 1; elementsLeft.find(*it + i) != elementsLeft.end(); i++) {
          toDelete.insert(*it + i);
          curr++;
        }
        ans = max(ans, curr);
      }
    }

    return ans;
  }
};

// optimized
int longestConsecutive(vector<int>& nums) {
  unordered_set<int> set;

  for (int i = 0; i < nums.size(); i++) {
    set.insert(nums[i]);
  }

  int ans = 0;

  for (auto it = set.begin(); it != set.end(); it++) {
    if (set.find(*it - 1) == set.end()) {
      int curr = 0;
      for (int i = 0; set.find(*it + i) != set.end(); i++) {
        curr++;
      }
      ans = max(ans, curr);
    }
  }

  return ans;
}