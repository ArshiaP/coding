// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  // Function to find the leaders in the array.
public:
  vector<int> leaders(int a[], int n)
  {
    vector<int> ans;
    int prev = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
      if (a[i] >= prev)
      {
        ans.push_back(a[i]);
        prev = a[i];
      }
      else
      {
        continue;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};