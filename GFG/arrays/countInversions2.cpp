// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long int inversions = 0;

void merge(long long arr[], long long l, long long mid, long long r) {
  long long n1 = mid - l + 1;
  long long n2 = r - mid;

  long long arr1[n1], arr2[n2];

  for (long long i = 0; i < n1; i++)
    arr1[i] = arr[l + i];

  for (long long i = 0; i < n2; i++)
    arr2[i] = arr[mid + 1 + i];

  long long i = 0, j = 0;
  long long k = l;

  while (i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      arr[k] = arr1[i];
      i++;
    } else {
      arr[k] = arr2[j];
      j++;
      inversions = inversions + (n1 - i);
    }
    k++;
  }

  while (i < n1) {
    arr[k] = arr1[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

void mergeSort(long long arr[], long long l, long long r) {
  if (l < r) {
    long long mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

long long int inversionCount(long long arr[], long long n) {
  inversions = 0;
  mergeSort(arr, 0, n - 1);
  return inversions;
}

int main() {
  long long arr[] = {1, 20, 5,6,7,8,9,10,7,5,4,3,2};
  int n = 13;
  long long int ans = inversionCount(arr, n);

  cout << ans << endl;
}