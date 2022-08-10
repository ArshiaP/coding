// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxSumIS(int arr[], int n) {
    vector<int> sums(n, 0);
    sums[0] = arr[0];
    int largest = 0;

    for (int i = 1; i < n; i++) {
      largest = 0;
      for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i] and largest < sums[j]) {
          largest = sums[j];
        }
      }
      sums[i] = arr[i] + largest;
    }

    return *max_element(sums.begin(), sums.end());
  }
};

//{ Driver Code Starts.
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];
  Solution ob;
  cout << ob.maxSumIS(a, n) << "\n";
  return 0;
}

// } Driver Code Ends