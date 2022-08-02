// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int getMinDiff(int arr[], int n, int k) {
    map<int, int> map;
    sort(arr, arr + n);
    int a = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] < k) {
        map[arr[i] + k]++;
        arr[i] = arr[i] + k;
        a++;
      } else {
        map[arr[i] - k]++;
        arr[i] = arr[i] - k;
      }
    }

    int dif = (--map.end())->first - map.begin()->first;

    for (int i = a; i < n; i++) {
      int toInsert = arr[i] + 2 * k;
      map[arr[i]]--;
      if (map[arr[i]] == 0) map.erase(arr[i]);
      map[toInsert]++;
      int newDiff = (--map.end())->first - map.begin()->first;
      dif = min(dif, newDiff);
    }

    return dif;
  }
};

//{ Driver Code Starts.
int main() {
  int n, k;
  cin >> k;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  Solution ob;
  auto ans = ob.getMinDiff(arr, n, k);
  cout << ans << "\n";

  return 0;
}
// } Driver Code Ends

