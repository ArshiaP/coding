//https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0#

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool sortbyCond(const pair<int, int>& a,const pair<int, int>& b) {
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return (a.second < b.second);
}

vector<int> sortByFrequency(vector<int>& arr, int n) {
  unordered_map<int, int> mp;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }
  vector<pair<int, int>> vec;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    vec.push_back({it->second, it->first});
  }
  sort(vec.begin(), vec.end(), sortbyCond);
  for (auto it : vec) {
    int count = it.first;
    while (count--) {
      ans.push_back(it.second);
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    vector<int> ans = sortByFrequency(arr, n);
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
  return 0;
}