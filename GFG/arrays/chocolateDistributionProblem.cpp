// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
  sort(a.begin(),a.end());
  long long minimum = LONG_MAX;
  for(int i = 0;i<n-m+1;i++){
    minimum = min(minimum, a[i+m-1] - a[i]);
  }
  return minimum;
}

int main()
{
  vector<long long> v = {7, 3, 2, 4, 9, 12, 56};
  long long ans = findMinDiff(v,7,3);
  cout<<ans;
}