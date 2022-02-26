// https://leetcode.com/problems/merge-intervals/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  vector<vector<int>> intervals{{2, 3}, {2, 2}, {3, 3}, {1, 3}, {5, 7}, {2, 2}, {4, 6}};

  sort(intervals.begin(), intervals.end());

  // for (vector<int> vec : intervals)
  // {
  //   for (int x : vec)
  //   {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }

  int curr = 0;
  int prev = 0;
  vector<vector<int>> ans;
  vector<int> a;

  while (curr < intervals.size())
  {
    prev = curr;
    a = {intervals[prev][0], intervals[curr][1]};
    // cout<<prev<<endl;

    if (curr + 1 < intervals.size() && a[1] >= intervals[curr + 1][0])
    {
      while (curr + 1 < intervals.size() && a[1] >= intervals[curr + 1][0])
      {
        a = {intervals[prev][0], max(a[1], intervals[curr][1])};
        curr++;
        a = {intervals[prev][0], max(a[1], intervals[curr][1])};
      }
    }
    else
    {
      a = {intervals[prev][0], intervals[curr][1]};
    }

    ans.push_back(a);
    if (curr < intervals.size() && a[1] >= intervals[curr][1])
      while (curr < intervals.size() && a[1] >= intervals[curr][1])
        curr++;
    else
      curr++;
  }

  for (vector<int> vec : ans)
  {
    for (int x : vec)
    {
      cout << x << " ";
    }
    cout << endl;
  }
}

//Solution from the net

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};