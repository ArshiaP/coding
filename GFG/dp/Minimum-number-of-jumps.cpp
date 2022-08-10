// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minJumps(int arr[], int n) {
    int i = 0;
    int jumps = 0;
    if (n == 1) return 0;

    while (i < n) {
      if (arr[i] == 0) {
        return -1;
      }
      int displacement = 0;
      int go = 0;
      for (int j = i + 1; j <= i + arr[i] and j < n; j++) {
        if (j == n - 1) {
          return jumps + 1;
        } else {
          if (displacement <= arr[j] + j) {
            displacement = arr[j] + j;
            go = j;
          }
        }
      }
      i = go;
      jumps++;
    }

    return jumps;
  }
};

//{ Driver Code Starts.

int main() {
  int n, i, j;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  Solution obj;
  cout << obj.minJumps(arr, n) << endl;

  return 0;
}

// } Driver Code Ends