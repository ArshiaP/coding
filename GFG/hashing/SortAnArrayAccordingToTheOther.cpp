// https://practice.geeksforgeeks.org/problems/relative-sorting4323/1

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
 public:
  // A1[] : the input array-1
  // N : size of the array A1[]
  // A2[] : the input array-2
  // M : size of the array A2[]

  // Function to sort an array according to the other array.
  vector<int> sortA1ByA2(vector<int> A1, int n, vector<int> A2, int m) {
    vector<int> ans;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
      map[A1[i]]++;
    }
    for (int i = 0; i < m; i++) {
      if (map.find(A2[i]) != map.end()) {
        int count = map[A2[i]];
        while (count--) {
          ans.push_back(A2[i]);
        }
        map.erase(A2[i]);
      }
    }
    int s = ans.size();
    for (auto it = map.begin(); it != map.end(); it++) {
      int count = it->second;
      while (count--) {
        ans.push_back(it->first);
      }
    }
    sort(ans.begin() + s, ans.end());
    return ans;
  }
};

// { Driver Code Starts.

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;

  vector<int> a1(n);
  vector<int> a2(m);

  for (int i = 0; i < n; i++) {
    cin >> a1[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> a2[i];
  }

  Solution ob;
  a1 = ob.sortA1ByA2(a1, n, a2, m);

  for (int i = 0; i < n; i++)
    cout << a1[i] << " ";

  cout << endl;

  return 0;
}
// } Driver Code Ends