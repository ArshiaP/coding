// https://practice.geeksforgeeks.org/problems/form-a-palindrome1455/1
// https://www.youtube.com/watch?v=IP4iqrh0mQk&t=453s

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countMin(string s) {
  if (s.length() <= 1) {
    return 0;
  }
  if (s.length() == 2) {
    if (s[1] == s[0]) {
      return 0;
    } else {
      return 1;
    }
  }

  vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
  for (int i = 0; i < s.length(); i++) {
    dp[i][i] = 1;
  }
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = 2;
    } else {
      dp[i][i + 1] = 1;
    }
  }

  int iEnd = s.length() - 2;
  int jStart = 2;

  int i = 0;
  int j = jStart;

  while (i < iEnd) {
    while (j < s.length()) {
      if (s[i] == s[j]) {
        dp[i][j] = 2 + dp[i + 1][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
      }
      i++;
      j++;
    }
    iEnd--;
    jStart++;
    i = 0;
    j = jStart;
  }

  return (s.length() - dp[0][s.length() - 1]);
}

int main() {
  string s = "potty";
  cout<<countMin(s)<<endl;
}