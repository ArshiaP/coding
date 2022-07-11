//https://practice.geeksforgeeks.org/problems/number-of-paths0926/1#
#include <bits/stdc++.h>
using namespace std;

int count(int i, int j, int m, int n){
  if(i==m-1 && j==n-1){
    return 1;
  }
  if(i >=m || j >=n){
    return 0;
  }
  return count(i+1,j,m,n) + count(i,j+1,m,n);
}

long long numberOfPaths(int m, int n) {
  return count(0,1,m,n) + count(1,0,m,n);
}

int main() {
  int n, m;
  cin >> m >> n;
  cout << numberOfPaths(m, n) << endl;
  return 0;
}  // } Driver Code Ends