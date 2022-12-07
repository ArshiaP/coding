// https://practice.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findSwapValues(int A[], int n, int B[], int m) {
    sort(A, A + n);
    sort(B, B + m);
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < n; i++) {
      sumA += A[i];
    }
    for (int i = 0; i < m; i++) {
      sumB += B[i];
    }
    if (sumA == sumB) {
      return 1;
    }
    int half = (sumA + sumB) / 2;
    for (int i = 0; i < n; i++) {
      int toFind = half - sumA + A[i];
      if (toFind > 0) {
        int lo = 0, hi = m - 1;
        int mid;
        while (hi - lo > 1) {
          int mid = (hi + lo) / 2;
          if (B[mid] < toFind) {
            lo = mid + 1;
          } else {
            hi = mid;
          }
        }
        if((B[lo]==toFind || B[hi]==toFind) && (sumA - A[i] + toFind)==(sumB - toFind + A[i])){
          return 1;
        }
      }
    }
    return -1;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  int b[m];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  Solution ob;
  cout << ob.findSwapValues(a, n, b, m);
  cout << "\n";

  return 0;
}


//editorial solution
int findSwapValues(int A[], int n, int B[], int m) {
    sort(A, A + n);
    sort(B, B + m);
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < n; i++) {
      sumA += A[i];
    }
    for (int i = 0; i < m; i++) {
      sumB += B[i];
    }
    if (sumA == sumB) {
      return 1;
    }
    int i = 0, j =0;
    while(i<n && j<m){
      int a = sumA - A[i] + B[j];
      int b = sumB - B[j] + A[i];
      if(a==b){
        return 1;
      }
      if(a<b){
        j++;
      }
      else{
        i++;
      }
    }
    return 0;
}