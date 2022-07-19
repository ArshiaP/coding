// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  bool canPair(vector<int> nums, int k) {
    if (nums.size() % 2 != 0) {
      return false;
    }
    int sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      map[nums[i] % k]++;
    }
    if (sum % k != 0) {
      return false;
    }
    for (int i = 0; i < k; i++) {
      if (map.find(i) != map.end()) {
        if (i * 2 == k || i==0) {
          if (map[i] % 2 == 0) {
            map.erase(i);
          } else {
            return false;
          }
        } else {
          if (map.find(k - i) != map.end() && map[i] == map[k - i]) {
            map.erase(i);
            map.erase(k - i);
          } else {
            return false;
          }
        }
      }
    }
    if (map.size() == 0) {
      return true;
    }
    return false;
  }
};

//{ Driver Code Starts.
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < nums.size(); i++) cin >> nums[i];
  Solution ob;
  bool ans = ob.canPair(nums, k);
  if (ans)
    cout << "True\n";
  else
    cout << "False\n";

  return 0;
}
// } Driver Code Ends