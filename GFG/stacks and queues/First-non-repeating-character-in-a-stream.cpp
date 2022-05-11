//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  string FirstNonRepeating(string a) {
    list<pair<char, int>> ll;
    ll.push_back({a[0], 1});

    for (int i = 1; i < a.size(); i++) {
      char c = NULL;
      bool flag = false;
      for (auto it = ll.begin(); it != ll.end(); it++) {
        if (it->first == a[i]) {
          it->second++;
          flag = true;
        }
        if (it->second == 1 and c==NULL) c = it->first;
        if (flag and c) break;
      }
      if (!flag) {
        ll.push_back({a[i], 1});
        if (!c) c = a[i];
      }
      if (!c)
        a[i] = '#';
      else
        a[i] = c;
    }

    return a;
  }
};

// { Driver Code Starts.
int main() {
  string A;
  cin >> A;
  Solution obj;
  string ans = obj.FirstNonRepeating(A);
  cout << ans << "\n";

  return 0;
}  // } Driver Code Ends