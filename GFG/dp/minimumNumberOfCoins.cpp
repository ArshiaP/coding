// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  vector<int> minPartition(int n) {
    vector<int> vec{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> ans;
    int v = 9;
    while (n != 0) {
      if (vec[v] > n) {
        v--;
      } else {
        n = n - vec[v];
        ans.push_back(vec[v]);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int N;
  cin >> N;

  Solution ob;
  vector<int> numbers = ob.minPartition(N);
  for (auto u : numbers)
    cout << u << " ";
  cout << "\n";

  return 0;
}
// } Driver Code Ends