// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

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

void merge(int arr1[], int arr2[], int n, int m)
{
  int temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (arr1[i] < arr2[j])
      {
        continue;
      }
      else
      {
        temp = arr1[i];
        arr1[i] = arr2[j];
        arr2[j] = temp;
      }
    }
  }
  sort(arr2, arr2 + m);
}

void merge2(int arr1[], int arr2[], int n, int m)
{
  int last1 = n - 1;
  int first2 = 0;
  while (last1 >= 0 && first2 < m)
  {
    if (arr1[last1] > arr2[first2])
    {
      long temp = arr1[last1];
      arr1[last1] = arr2[first2];
      arr2[first2] = temp;
      first2++;
      last1--;
    }
    else
    {
      break;
    }
  }
  sort(arr1, arr1 + n);
  sort(arr2, arr2 + m);
}

void merge3(int arr1[], int arr2[], int n, int m)
{
  int temp;
  static int size1 = n;
  static int size2 = m;
  if (n == 0)
  {
    sort(arr1, arr1 + size1);
    sort(arr2, arr2 + size2);
  }
  if (m == 0)
  {
    n--;
    merge2(arr1, arr2, n, size2);
  }
  if (arr1[n - 1] < arr2[m - 1])
  {

    merge2(arr1, arr2, n, m - 1);
  }
  else
  {
    temp = arr1[n - 1];
    arr1[n - 1] = arr2[m - 1];
    arr2[m - 1] = temp;
    merge2(arr1, arr2, n, m - 1);
  }
}

int main()
{
  int arr1[] = {0, 2, 6, 8, 9};
  int arr2[] = {1, 3, 5, 7};
  int n = *(&arr1 + 1) - arr1;
  int m = *(&arr2 + 1) - arr2;
  merge2(arr1, arr2, n, m);
  for (int i = 0; i < n; i++)
  {
    cout << arr1[i] << endl;
  }
  cout << endl;
  for (int i = 0; i < m; i++)
  {
    cout << arr2[i] << endl;
  }
}