// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  long long maxSubarraySum(int arr[], int n)
  {

    int max_so_far = arr[0];
    int curr_max = arr[0];

    for (int i = 1; i < n; i++)
    {
      curr_max = max(arr[i], curr_max + arr[i]);
      max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
  }
};