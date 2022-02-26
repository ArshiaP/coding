// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1

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
  void rearrange(long long *arr, int n)
  {
    int *a = new int[n];
    int j = 0;

    for (int i = 0; i < (n + 1) / 2; i++)
    {
      a[j++] = arr[n - 1 - i];
      if (n % 2 == 0)
        a[j++] = arr[i];
      else
      {
        if (j != n)
          a[j++] = arr[i];
      }
    }
    for (int i = 0; i < n; i++)
      arr[i] = a[i];
  }
};

class Solution2
{

  //   How does expression “arr[i] += arr[max_index] % max_element * max_element” work ?
  // The purpose of this expression is to store two elements at index arr[i]. arr[max_index] is stored as multiplier and “arr[i]” is stored as remainder. For example in {1 2 3 4 5 6 7 8 9}, max_element is 10 and we store 91 at index 0. With 91, we can get original element as 91%10 and new element as 91/10.

public:
  void rearrange(int arr[], int n)
  {
    // initialize index of first minimum and first
    // maximum element
    int max_idx = n - 1, min_idx = 0;

    // store maximum element of array
    int max_elem = arr[n - 1] + 1;

    // traverse array elements
    for (int i = 0; i < n; i++)
    {
      // at even index : we have to put maximum element
      if (i % 2 == 0)
      {
        arr[i] += (arr[max_idx] % max_elem) * max_elem;
        max_idx--;
      }

      // at odd index : we have to put minimum element
      else
      {
        arr[i] += (arr[min_idx] % max_elem) * max_elem;
        min_idx++;
      }
    }

    // array elements back to it's original form
    for (int i = 0; i < n; i++)
      arr[i] = arr[i] / max_elem;
  }
};

int main()
{
  long long arr[] = {1, 2, 3, 4, 5, 6};
  int n = *(&arr + 1) - arr;
  Solution s;
  s.rearrange(arr, n);
  for (auto x : arr)
  {
    cout << x << endl;
  }
}