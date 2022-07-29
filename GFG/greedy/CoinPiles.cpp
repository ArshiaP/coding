// https://practice.geeksforgeeks.org/problems/coin-piles5152/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minSteps(int a[], int n, int k) {
    sort(a, a + n);
    int i = 0;
    int j = n - 1;
    int ans = 0;
    while (a[j] - a[i] > k) {
      int diff = a[j] - a[i];
      if (diff - k == a[i] and i + 1 != j) {
        int diff1 = a[j] - a[i + 1];
        int diff2 = a[j - 1] - a[i];
        if (diff1 > diff2) {
          j--;
          ans += diff - k;
        } else {
          ans += a[i];
          i++;
        }
      } else if (diff - k >= a[i]) {
        ans += a[i];
        i++;
      } else if (diff - k < a[i]) {
        ans += diff - k;
        j--;
      }
    }
    return ans;
  }
};

int main() {
  int N, K;
  cin >> N >> K;
  int A[N];
  for (int i = 0; i < N; i++)
    cin >> A[i];
  Solution ob;
  cout << ob.minSteps(A, N, K) << endl;

  return 0;
}
// } Driver Code Ends

class Solution {
 public:
  int minSteps(int A[], int N, int K) {
    vector<int> a(N), p(N, 0);
    for (int i = 0; i < N; i++)
      a[i] = A[i];

    sort(a.begin(), a.end());

    p[0] = a[0];

    for (int i = 1; i < N; i++)
      p[i] = p[i - 1] + a[i];

    int ans = INT_MAX, prev = 0;

    for (int i = 0; i < N; i++) {
      int pos = upper_bound(a.begin() + i, a.end(), a[i] + K) - a.begin();

      if (i > 0 && a[i] != a[i - 1])
        prev = p[i - 1];

      ans = min(ans, prev + p[N - 1] - p[pos - 1] - (N - pos) * (a[i] + K));
    }
    return ans;
  }
};