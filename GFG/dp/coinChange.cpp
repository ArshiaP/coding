// https://practice.geeksforgeeks.org/problems/coin-change2448/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  long long int count(int S[], int m, int n) {
    vector<vector<long long int>> dp(n + 1, vector<long long int>(m + 1, 0));
    for (int j = 1; j <= m; j++) {
      dp[0][j] = 1;
    }
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        dp[i][j] = dp[i][j-1];
        if(S[j-1] <= i){
          dp[i][j] += dp[i-S[j-1]][j];
        }
      }
    }
    return dp[n][m];
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  int arr[m];
  for (int i = 0; i < m; i++) cin >> arr[i];
  Solution ob;
  cout << ob.count(arr, m, n) << endl;

  return 0;
}