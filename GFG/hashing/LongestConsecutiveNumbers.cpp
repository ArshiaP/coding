// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int findLongestConseqSubseq(int arr[], int N) {
    unordered_set<int> set;
    int ans = 0;
    int run = 1;
    for (int i = 0; i < N; i++) {
      set.insert(arr[i]);
    }
    for (int i = 0; i < N; i++) {
      if (set.find(arr[i]) != set.end() && set.find(arr[i]-1) == set.end()) {
        set.erase(arr[i]);
        run = 1;
        int next = arr[i] + 1;
        while(set.find(next) != set.end()){
          run++;
          set.erase(next);
          next++;
        }
        ans = max(ans,run);
      }
    }
    return ans;
  }
};

int main() {
  int n, i, a[100001];
  cin >> n;
  for (i = 0; i < n; i++)
    cin >> a[i];
  Solution obj;
  cout << obj.findLongestConseqSubseq(a, n) << endl;

  return 0;
}
// } Driver Code Ends