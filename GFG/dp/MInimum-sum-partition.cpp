// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minDifference(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++)
      dp[i][0] = 1;

    int ans = INT_MAX;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= sum; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j - arr[i - 1] >= 0 && dp[i - 1][j - arr[i - 1]] == 1) {
          dp[i][j] = dp[i - 1][j - arr[i - 1]];
        }
        if (dp[i][j] and sum - j - j >= 0) {
          ans = min(ans, sum - j - j);
        }
      }
    }

    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  Solution ob;
  cout << ob.minDifference(a, n) << "\n";
  return 0;
}