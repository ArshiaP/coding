// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int equalPartition(int n, int arr[]) {
    int sum = 0;
    sum = accumulate(arr, arr + n, sum);
    if (sum % 2) {
      return 0;
    }
    sum = sum / 2;

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));

    dp[0][0] = 1;
    if (arr[0] <= sum) {
      dp[0][arr[0]] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j <= sum; j++) {
        if (dp[i][j]) {
          dp[i + 1][j] = 1;
          if (j + arr[i + 1] < sum) {
            dp[i + 1][j + arr[i + 1]] = 1;
          }
          if (j + arr[i + 1] == sum) {
            return 1;
          }
        }
      }
    }

    return 0;
  }
};

int main() {
  int N;
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++)
    cin >> arr[i];

  Solution ob;
  if (ob.equalPartition(N, arr))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}
// } Driver Code Ends