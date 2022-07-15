// https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
 //doesnt pass all TCs
  vector<vector<int>> fourSum(vector<int> &arr, int k) {
    vector<vector<int>> ans;
    unordered_map<int, int> map;
    set<vector<int>> set;
    for (int i = 0; i < arr.size(); i++) {
      map[arr[i]] = i;
    }
    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        for (int b = j + 1; b < arr.size(); b++) {
          vector<int> res;
          int sum = k - arr[i] - arr[j] - arr[b];
          if (map.find(sum) != map.end()) {
            int count = 0;
            if (arr[i] == sum) {
              count++;
            }
            if (arr[j] == sum) {
              count++;
            }
            if (arr[b] == sum) {
              count++;
            }
            if (count == 0) {
              res = {arr[i], arr[j], arr[b], sum};
              sort(res.begin(), res.end());
              set.insert(res);
            } else if (map[sum] == count) {
              continue;
            } else {
              res = {arr[i], arr[j], arr[b], sum};
              sort(res.begin(), res.end());
              set.insert(res);
            }
          }
        }
      }
    }
    for (auto it = set.begin(); it != set.end(); it++) {
      ans.push_back(*it);
    }
    return ans;
  }
};

vector<vector<int>> fourSum(vector<int> &arr, int b) {
    sort(arr.begin(), arr.end());
    unordered_map<int, int> map;
    vector<vector<int>> ans;
    unordered_set<long long int> set;

    for (int i = 0; i < arr.size(); i++) {
      map[arr[i]] = i;
    }

    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        for (int k = j + 1; k < arr.size(); k++) {
          int sum = arr[i] + arr[j] + arr[k];
          int rem = b - sum;
          if (map.find(rem) != map.end()) {
            if (map[rem] > k) {
              vector<int> a{arr[i], arr[j], arr[k], rem};
              long long int con =
                  arr[i] * 1000000000 + arr[j] * 1000000 + arr[k] * 1000 + rem; //storing int in an unordered set for constant time retrieval.
              if (set.find(con) == set.end()) {
                set.insert(con);
                ans.push_back(a);
              }
            }
          }
        }
      }
    }
  
    return ans;
}

int main() {
  int n, k, i;
  cin >> n >> k;
  vector<int> a(n);
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  Solution ob;
  vector<vector<int>> ans = ob.fourSum(a, k);
  for (auto &v : ans) {
    for (int &u : v) {
      cout << u << " ";
    }
    cout << "$";
  }
  if (ans.empty()) {
    cout << -1;
  }
  cout << "\n";
  return 0;
}