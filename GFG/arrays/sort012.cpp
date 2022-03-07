// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

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

// dutch flag problem
class Solution
{
public:
  void sort012(int a[], int n)
  {
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi)
    {
      switch (a[mid])
      {

      // If the element is 0
      case 0:
        a[mid] = a[lo];
        a[lo] = 0;
        mid++;
        lo++;
        break;

      // If the element is 1 .
      case 1:
        mid++;
        break;

      // If the element is 2
      case 2:
        a[mid] = a[hi];
        a[hi] = 2;
        hi--;
        break;
      }
    }
  }
};

void sort012(int a[], int n)
{
  int zero = 0;
  int one = 0;
  int two = 0;

  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0)
    {
      zero++;
    }
    else if (a[i] == 1)
    {
      one++;
    }
    else
    {
      two++;
    }
  }
  int i = 0;
  for (; zero != 0; i++)
  {
    a[i] = 0;
    zero--;
  }
  for (; one != 0; i++)
  {
    a[i] = 1;
    one--;
  }
  for (; two != 0; i++)
  {
    a[i] = 2;
    two--;
  }
}

int main()
{
  int a[] = {0, 2, 1, 2, 0};
  int n = 5;
  sort012(a, n);
  for (auto x : a)
  {
    cout << x << endl;
  }
}