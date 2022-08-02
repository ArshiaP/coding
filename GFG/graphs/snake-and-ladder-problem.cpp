// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minThrow(int N, int arr[]) {
    queue<pair<int, int>> q;  // {destination vertex , throws}
    unordered_map<int, int> map;
    for (int i = 0; i < 2 * N; i += 2) {
      map[arr[i]] = arr[i + 1];
    }
    q.push({1, 0});
    vector<int> visited(31, 0);
    visited[1] = 1;
    int cell, moves, x;
    while (!q.empty()) {
      cell = q.front().first;
      moves = q.front().second;
      q.pop();
      if (cell == 30) {
        return moves;
      }
      for (int i = 1; i < 7; i++) {
        if (!visited[cell + i]) {
          if (map.find(cell + i) != map.end()) {
            visited[cell + i] = 1;
            visited[map[cell + i]] = 1;
            q.push({map[cell + i], moves + 1});
          } else {
            q.push({cell + i, moves + 1});
            visited[cell + i] = 1;
          }
        }
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int N;
  cin >> N;
  int arr[2 * N];
  for (int i = 0; i < 2 * N; i++)
    cin >> arr[i];

  Solution ob;
  cout << ob.minThrow(N, arr) << "\n";

  return 0;
}
// } Driver Code Ends