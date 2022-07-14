//https://practice.geeksforgeeks.org/problems/josephus-problem/1#
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int josephus(int n, int k) {
    if(n==1){
      return 1;
    }
    return (josephus(n-1,k)+k-1)%n+1;
  }
};

int main() {
  int n, k;
  cin >> n >> k;  
  Solution ob;
  cout << ob.josephus(n, k) << endl;
  return 0;
} 