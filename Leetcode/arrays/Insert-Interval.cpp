// https://leetcode.com/problems/insert-interval/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    if (intervals.size() == 0) {
      ans.push_back(newInterval);
      return ans;
    }
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        if (i == intervals.size() - 1) {
          ans.push_back(newInterval);
        }
      } else if (intervals[i][0] > newInterval[1]) {
        ans.push_back(newInterval);
        for (int j = i; j < intervals.size(); j++) {
          ans.push_back(intervals[j]);
        }
        return ans;
      } else {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        if (i == intervals.size() - 1) {
          ans.push_back(newInterval);
        }
      }
    }
    return ans;
  }
};

int main() {
  vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<int> newInterval = {4, 8};
  Solution s;
  vector<vector<int>> ans = s.insert(intervals, newInterval);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < 2; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    if (intervals.size() == 0) {
      ans.push_back(newInterval);
      return ans;
    }
    int startIdx = 0;
    for (int i = 0; i < intervals.size(); i++) {
      if (newInterval[0] > intervals[i][0]) {
        if (i != 0) {
          ans.push_back(intervals[startIdx]);
        } else if (newInterval[1] < intervals[i][1]) {
          ans.push_back(intervals[i]);
          for (int j = i + 1; j < intervals.size(); j++) {
            ans.push_back(intervals[j]);
          }
          return ans;
        }
        startIdx = i;
      }
    }
    for (int i = startIdx; i < intervals.size(); i++) {
      if (newInterval[1] < intervals[i][0]) {
        ans.push_back(newInterval);
        for (int j = i; j < intervals.size(); j++) {
          ans.push_back(intervals[j]);
        }
        return ans;
      } else {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        if (i == intervals.size() - 1) {
          ans.push_back(newInterval);
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    if (intervals.size() == 0) {
      ans.push_back(newInterval);
      return ans;
    }
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        if (i == intervals.size() - 1) {
          ans.push_back(newInterval);
        }
      } else if (intervals[i][0] > newInterval[1]) {
        ans.push_back(newInterval);
        for (int j = i; j < intervals.size(); j++) {
          ans.push_back(intervals[j]);
        }
        return ans;
      } else {
        int j = i;
        while (intervals[j][0] <= newInterval[1]) {
          newInterval[0] = min(newInterval[0], intervals[j][0]);
          newInterval[1] = max(newInterval[1], intervals[j][1]);
          j++;
        }
        i = j - 1;
        if (i == intervals.size() - 1) {
          ans.push_back(newInterval);
        }
      }
    }
    return ans;
  }
};

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
  vector<vector<int>> ans;
  if (intervals.size() == 0) {
    ans.push_back(newInterval);
    return ans;
  }
  for (int i = 0; i < intervals.size(); i++) {
    if (intervals[i][1] < newInterval[0]) {
      ans.push_back(intervals[i]);
      if (i == intervals.size() - 1) {
        ans.push_back(newInterval);
      }
    } else if (intervals[i][0] > newInterval[1]) {
      ans.push_back(newInterval);
      for (int j = i; j < intervals.size(); j++) {
        ans.push_back(intervals[j]);
      }
      return ans;
    } else {
      int j = i;
      int start = newInterval[0];
      int end = newInterval[1];
      while (intervals[j][0] <= newInterval[1]) {
        start = min(start, intervals[j][0]);
        end = max(end, intervals[j][1]);
        j++;
      }
      i = j - 1;
      if (i == intervals.size() - 1) {
        ans.push_back(newInterval);
      }
    }
  }
  return ans;
}


class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int flag = 0;
    if (intervals.size() == 0) {
      ans.push_back(newInterval);
      return ans;
    }
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        if (i == intervals.size() - 1) {
          ans.push_back(newInterval);
        }
      } else if (intervals[i][0] > newInterval[1]) {
        if (flag == 0)
          ans.push_back(newInterval);
        for (int j = i; j < intervals.size(); j++) {
          ans.push_back(intervals[j]);
        }
        return ans;
      } else {
        int j = i;
        int start = newInterval[0];
        int end = newInterval[1];
        while (j < intervals.size() && intervals[j][0] <= end) {
          start = min(start, intervals[j][0]);
          end = max(end, intervals[j][1]);
          j++;
        }
        ans.push_back({start, end});
        flag = 1;
        i = j - 1;
      }
    }
    return ans;
  }
};