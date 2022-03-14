// https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void zigZag(int arr[], int n)
{
  for (int i = 1; i < n; i += 2)
  {

    if (arr[i] < arr[i - 1])
    {
      swap(arr[i], arr[i - 1]);
    }
    if (i != n - 1 && arr[i] < arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
    }
  }
}

int main()
{
  int arr[] = {1, 4, 3, 2};
  zigZag(arr, 4);
  for (auto x : arr)
  {
    cout << x << endl;
  }
}