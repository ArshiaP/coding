// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < nums1.size(); i++) {
      sum1 += nums1[i];
    }
    for (int i = 0; i < nums2.size(); i++) {
      sum2 += nums2[i];
    }
    int i = 0, j = 0;  // i is for bigger val, j is for smaller sum array

    // nums 1 has bigger sum array
    if (sum1 < sum2) {
      nums1.swap(nums2);
    }
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end());
    int count = 0;
    int diff = abs(sum1 - sum2);
    if (diff == 0) {
      return 0;
    }
    while (i < nums1.size() || j < nums2.size()) {
      count++;
      if (i < nums1.size() && j < nums2.size() && nums1[i] - 1 > 6 - nums2[j]) {
        diff -= nums1[i] - 1;
        i++;
      } else if (i < nums1.size() && j < nums2.size() && nums1[i] - 1 <= 6 - nums2[j]) {
        diff -= 6 - nums2[j];
        j++;
      } else if (i < nums1.size() && j >= nums2.size()) {
        diff -= nums1[i] - 1;
        i++;
      } else if (i >= nums1.size() && j < nums2.size()) {
        diff -= 6 - nums2[j];
        j++;
      }
      if (diff <= 0) {
        return count;
      }
    }
    return -1;
  }
};



int minOperations(vector<int>& nums1, vector<int>& nums2) {
  unordered_map<int, int> greater;
  unordered_map<int, int> lesser;
  int sum1 = 0;
  int sum2 = 0;

  for (auto i : nums1) {
    sum1 += i;
  }
  for (auto i : nums2) {
    sum2 += i;
  }

  int diff;

  if (sum1 > sum2) {
    diff = sum1 - sum2;
    for (auto i : nums1) {
      greater[i]++;
    }
    for (auto i : nums2) {
      lesser[i]++;
    }
  } else if (sum1 < sum2) {
    diff = sum2 - sum1;
    for (auto i : nums2) {
      greater[i]++;
    }
    for (auto i : nums1) {
      lesser[i]++;
    }
  } else {
    return 0;
  }

  int count = 0;

  int i = 6;
  int j = 1;

  while (i >= 1 or j <= 6) {
    // i and j exist
    if (greater.find(i) != greater.end() and lesser.find(j) != lesser.end()) {
      if (i - 1 > 6 - j) {
        while (greater[i] and diff > 0) {
          diff -= i - 1;
          count++;
          greater[i]--;
        }
        i--;
      } else {
        while (lesser[j] and diff > 0) {
          diff -= 6 - j;
          count++;
          lesser[j]--;
        }
        j++;
      }
    }
    // only j exists
    else if (greater.find(i) == greater.end() and lesser.find(j) != lesser.end()) {
      while (lesser[j] and diff > 0) {
        diff -= 6 - j;
        count++;
        lesser[j]--;
      }
      j++;
    }
    // only i exists
    else if (greater.find(i) != greater.end() and lesser.find(j) == lesser.end()) {
      while (greater[i] and diff > 0) {
        diff -= i - 1;
        count++;
        greater[i]--;
      }
      i--;
    }
    // neither exist
    else {
      i--;
      j++;
    }
    if (diff <= 0) {
      return count;
    }
  }
  return -1;
}

int main() {
  vector<int> a = {1};
  vector<int> b = {6, 6};
  Solution ob;
  cout << ob.minOperations(a, b) << endl;
}