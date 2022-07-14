//https://practice.geeksforgeeks.org/problems/special-keyboard3018/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  long long int solve(int x, int y,vector<int>& store){
    if(x<=0){
      return -1;
    }
    return max((long long int)store[x]*y,solve(x-1,y+1,store));
  }

  long long int optimalKeys(int N) {
    vector<int> store(N+1);
    for(int i=1;i<=3;i++){
      store[i] = i;
    }
    for(int i=4;i<=N;i++){
      int x = i-3; 
      int y = 2;
      long long int ans = solve(x,y,store);
      store[i] = max(ans,(long long int)i);
    }
    return store[N];
  }
};

int main() {
  int N;
  cin >> N;

  Solution ob;
  cout << ob.optimalKeys(N) << "\n";

  return 0;
}  // } Driver Code Ends