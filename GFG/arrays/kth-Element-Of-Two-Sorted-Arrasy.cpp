// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int recurse(int arr1[], int arr2[], int n, int m, int k, int b1, int e1, int b2, int e2) {
    if (n + m == 2) {
      if (k == 1) {
        return min(arr1[b1], arr2[b2]);
      } else {
        return max(arr1[b1], arr2[b2]);
      }
    }
    int sum = n + m;
    sum /= 2;
    int mid1 = (b1 + e1) / 2;
    int mid2 = (b2 + e2) / 2;
    if (k > sum) {
      k = k - (mid1 - b1) - (mid2 - b2);
      b1 = mid1;
      b2 = mid2;
      n = e1 - b1 + 1;
      m = e2 - b2 + 1;
      return recurse(arr1, arr2, n, m, k, b1, e1, b2, e2);
    } else {
      e1 = mid1;
      e2 = mid2;
      n = e1 - b1 + 1;
      m = e2 - b2 + 1;
      return recurse(arr1, arr2, n, m, k, b1, e1, b2, e2);
    }
  }
  int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    if (k == 1) {
      return min(arr1[0], arr2[0]);
    }
    return recurse(arr1, arr2, n, m, k, 0, n - 1, 0, m - 1);
  }
};

int main() {
  int arr1[] = {2, 3, 6, 7, 9};
  int arr2[] = {1, 4, 8, 10};
  Solution ob;
  cout << ob.kthElement(arr1, arr2, 5, 4, 5) << endl;
  return 0;
}