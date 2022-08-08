// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int N;
  int M;
  bool isValid(int a, int b) {
    return a >= 0 and a < N and b >= 0 and b < M;
  }

  int longestCommonSubstr(string s1, string s2, int n, int m) {
    N = n;
    M = m;
    int ans = 0;
    vector<vector<int>> vec(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s1[i] == s2[j]) {
          vec[i][j] = (isValid(i - 1, j - 1) ? vec[i - 1][j - 1] : 0) + 1;
          ans = max(ans, vec[i][j]);
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    Solution ob;

    cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
  }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends