// https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int pageFaults(int N, int C, int pages[]) {
    list<int> myList;
    unordered_map<int, list<int>::iterator> map;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (map.find(pages[i]) == map.end()) {
        ans++;
        if (myList.size() == C) {
          int ele = myList.front();
          map.erase(ele);
          myList.pop_front();
        }
        myList.push_back(pages[i]);
        auto it = myList.end();
        it--;
        map.insert({pages[i], it});
      } else {
        auto it = map[pages[i]];
        myList.erase(it);
        myList.push_back(pages[i]);
        it = myList.end();
        it--;
        map[pages[i]] = it;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int N, C;
  cin >> N;
  int pages[N];
  for (int i = 0; i < N; i++)
    cin >> pages[i];
  cin >> C;

  Solution ob;
  cout << ob.pageFaults(N, C, pages) << "\n";
  return 0;
}
// } Driver Code Ends