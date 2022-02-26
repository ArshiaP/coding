// https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1

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
  int countTriplet(int arr[], int n)
  {
    sort(arr, arr + n);
    int i;
    int j;
    int sum;
    int count = 0;
    for (int last = n - 1; last >= 0; last--)
    {
      i = 0;
      j = last - 1;

      while (i < j)
      {
        sum = arr[i] + arr[j];

        if (arr[last] == sum)
        {
          count++;
          i++;
          j--;
          //distinct integers
        }
        else if (sum < arr[last])
        {
          i++;
        }
        else
        {
          j--;
        }
      }
    }
    return count;
  }
};

int countTriplet(int arr[], int n) {
  sort(arr, arr + n);

  int j, k;

  int ans = 0;

  for (int i = n - 1; i > 1; i--) {
    j = 0;
    k = i - 1;

    while (j < k && k < i) {
      int sum = arr[j] + arr[k];
      if (sum < arr[i]) {
        j++;
      } else if (sum > arr[i]) {
        k--;
      } else {
        ans++;
        j++;
        k--;
      }
    }
  }

  return ans;
}

int main()
{
  Solution s;
  int arr[] = {1,5,3,2};
  int n = *(&arr + 1) - arr;
  int count = s.countTriplet(arr, n);
  cout << count;
}