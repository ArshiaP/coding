// https://practice.geeksforgeeks.org/problems/box-stacking/1

#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static bool comp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    return (get<0>(t1) * get<1>(t1)) > (get<0>(t2) * get<1>(t2));
  }
  // check if t2 can go on top of t1
  bool isFeasible(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    return get<0>(t2) < get<0>(t1) and get<1>(t2) < get<1>(t1);
  }
  int maxHeight(int height[], int width[], int length[], int n) {
    vector<tuple<int, int, int>> boxes;
    vector<int> ans(6 * n, 0);
    for (int i = 0; i < n; i++) {
      auto tup1 = make_tuple(length[i], width[i], height[i]);
      auto tup2 = make_tuple(width[i], length[i], height[i]);
      auto tup3 = make_tuple(width[i], height[i], length[i]);
      auto tup4 = make_tuple(height[i], width[i], length[i]);
      auto tup5 = make_tuple(length[i], height[i], width[i]);
      auto tup6 = make_tuple(height[i], length[i], width[i]);
      boxes.push_back(tup1);
      boxes.push_back(tup2);
      boxes.push_back(tup3);
      boxes.push_back(tup4);
      boxes.push_back(tup5);
      boxes.push_back(tup6);
    }
    sort(boxes.begin(), boxes.end(), comp);

    for (int i = 0; i < 6 * n; i++) {
      ans[i] = get<2>(boxes[i]);
      int largest = 0;
      for (int j = 0; j < i; j++) {
        if (ans[j] > largest and isFeasible(boxes[j], boxes[i])) {
          largest = ans[j];
        }
      }
      ans[i] += largest;
    }

    return *max_element(ans.begin(), ans.end());
  }
};

int main() {
  int n;
  cin >> n;
  int A[105], B[105], C[105];
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int j = 0; j < n; j++) cin >> B[j];
  for (int k = 0; k < n; k++) cin >> C[k];
  Solution ob;
  cout << ob.maxHeight(A, B, C, n) << endl;
  return 0;
}

// } Driver Code Ends