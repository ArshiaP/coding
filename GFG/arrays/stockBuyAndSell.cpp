// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> stockBuySell(vector<int> A, int n)
{
  vector<vector<int>> ans;
  int left = 0;
  int right = 0;
  while (right < n)
  {
    while (right + 1 < n and A[right] < A[right + 1])
    {
      right++;
    }
    if (left != right)
    {
      ans.push_back({left, right});
    }
    right++;
    left = right;
  }
  return ans;
}

int main()
{
  vector<int> v = {100, 180, 260, 310, 40, 535, 695};
  vector<vector<int>> ans = stockBuySell(v, 7);
  for (auto a : ans)
  {
    for (auto x : a)
    {
      cout << x << endl;
    }
    cout << endl;
  }
}