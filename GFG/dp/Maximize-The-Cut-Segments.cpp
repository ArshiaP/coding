// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maximizeTheCuts(int n, int x, int y, int z) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int a = 0, b = 0, c = 0;
      if (i - x > 0 and dp[i - x] != 0) {
        a = dp[i - x] + 1;
      }
      else if(i-x==0){
        a=1;
      }
      if (i - y > 0 and dp[i - y] != 0) {
        b = dp[i - y] + 1;
      }
      else if(i-y==0){
        b=1;
      }
      if (i - z > 0 and dp[i - z] != 0) {
        c = dp[i - z] + 1;
      }
      else if(i-z==0){
        c=1;
      }
      dp[i] = max(a, max(b, c));
    }
    return dp[n];
  }
};

int main() {
  int n;
  cin >> n;
  int x, y, z;
  cin >> x >> y >> z;
  Solution obj;
  cout << obj.maximizeTheCuts(n, x, y, z) << endl;
  return 0;
}