//https://practice.geeksforgeeks.org/problems/max-length-chain/1
#include <bits/stdc++.h>
using namespace std;

struct val {
  int first;
  int second;
};

class Solution {
 public:
  /*You are required to complete this method*/
  int maxChainLen(struct val p[], int n) {
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
      vec.push_back({p[i].second,p[i].first});
    }
    sort(vec.begin(),vec.end());
    int ans = 0;
    int endLength = 0;
    for(int i=0;i<n;i++){
      if(vec[i].second > endLength){
        ans++;
        endLength = vec[i].first;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int n;
  cin >> n;
  val p[n];
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  Solution ob;
  cout << ob.maxChainLen(p, n) << endl;
  return 0;
}
// } Driver Code Ends