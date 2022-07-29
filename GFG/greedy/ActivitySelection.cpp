// https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int activitySelection(vector<int> start, vector<int> end, int n) {
    vector<pair<int, int>> arr;
    for(int i=0; i<n; i++){
      arr.push_back({end[i], start[i]});
    }
    sort(arr.begin(), arr.end());
    int ans = 1;
    int latest = arr[0].first;
    for(int i=1; i<n; i++){
      if(arr[i].second>latest){
        ans++;
        latest = arr[i].first;
      }
    }
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> start(n), end(n);

  for (int i = 0; i < n; i++)
    cin >> start[i];
  for (int i = 0; i < n; i++)
    cin >> end[i];
  Solution ob;

  cout << ob.activitySelection(start, end, n) << endl;

  return 0;
}

// } Driver Code Ends