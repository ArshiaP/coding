// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
 public:
  ll findSubarray(vector<ll> arr, int n) {
    unordered_map<int, int> map;
    map[0]++;
    ll prefixSum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      prefixSum += arr[i];
      if (map.find(prefixSum) != map.end()) {
        ans += map[prefixSum];
      }
      map[prefixSum]++;
    }
    return ans;
  }
};

int main() {
  int n;
  // cin >> n;
  vector<ll> arr{0, 0, 5, 5, 0, 0};
  // for (int i = 0; i < n; i++)
  //   cin >> arr[i];
  Solution ob;
  cout << ob.findSubarray(arr, 6) << "\n";
  return 0;
}