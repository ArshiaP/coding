// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n) {
  stack<long long> st;
  vector<long long> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (st.empty()) {
      ans.push_back(-1);
      st.push(arr[i]);
    } else if (st.top() > arr[i]) {
      ans.push_back(st.top());
      st.push(arr[i]);
    } else {
      while (!st.empty() and st.top() < arr[i]) {
        st.pop();
      }
      if (st.empty()) {
        ans.push_back(-1);
        st.push(arr[i]);
      } else {
        ans.push_back(st.top());
        st.push(arr[i]);
      }
    }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  vector<long long> arr = {6, 8, 0, 1, 3};
  int n = 5;
  vector<long long> ans = nextLargerElement(arr, n);
  for (auto c : ans) {
    cout << c << endl;
  }
}