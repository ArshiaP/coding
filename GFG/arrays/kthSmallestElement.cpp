//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void swap(int i, int j, int arr[]){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int arr[], int l, int r) {
  int pivot = arr[r];
  int i = l - 1;
  for (int j = l; j < r; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(i, j, arr);
    }
  }
  swap(i + 1, r, arr);
  return i + 1;
}

void quick(int arr[], int l, int r, int k, int* ans) {
  if (l <= r) {
    int p = partition(arr, l, r);
    if (p == k - 1) {
      *ans = arr[p];
    } else if (p > k - 1) {
      quick(arr, l, p - 1, k, ans);
    } else {
      quick(arr, p + 1, r, k, ans);
    }
  }
}

int kthSmallest(int arr[], int l, int r, int k) {
  int ans = 0;
  quick(arr, l, r, k, &ans);
  return ans;
}

int main() {
  int arr[] = {7, 10, 4, 3, 20, 15};
  int k = 1;
  int ans = kthSmallest(arr, 0, 5, k);
  cout << ans << endl;
}