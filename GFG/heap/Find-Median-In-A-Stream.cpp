// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#

// chalega nahi, par sahi hai

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 private:
  multiset<int> avl;
  multiset<int>::iterator it;

 public:
  // Function to insert heap.
  void insertHeap(int &x) {
    avl.insert(x);
    if (avl.size() == 1) {
      it = avl.begin();
    } else if (avl.size() % 2 and x > *it) {
      it++;
    } else if (!(avl.size() % 2) and x < *it) {
      it--;
    }
  }

  // Function to balance heaps.
  void balanceHeaps() {
  }

  // Function to return Median.
  double getMedian() {
    int n = avl.size();
    if (avl.size() % 2) {
      return *it;
    } else {
      multiset<int>::iterator it2 = it;
      advance(it2, 1);
      return (*it + *it2) / 2;
    }
  }
};

// { Driver Code Starts.

int main() {
  int n, x;

  Solution ob;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    ob.insertHeap(x);
    cout << floor(ob.getMedian()) << endl;
  }
  return 0;
}  // } Driver Code Ends