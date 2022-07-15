// https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxLen(vector<int>& A, int n) {
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
      sum+=A[i];
      if(mp.find(sum)!=mp.end()){
        ans=max(ans,i-mp[A[i]]);
      }else{
        mp[A[i]] = i;
      }
    }
    return ans;
  }
};

class Solution2 {
 public:
  int maxLen(vector<int>& A, int n) {
    unordered_map<int, pair<int,int>> mp;
    int sum = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
      sum+=A[i];
      if(mp.find(sum)!=mp.end()){
        mp[sum].second = i;
      }else{
        mp[sum] = {i,-1};
      }
    }
    for(auto it=mp.begin();it!=mp.end();it++){
      
      //if 0 occurs in prefix sum that means all elements uptil that index add upto 0
     if(it->first == 0 && it->second.second!=-1){
        ans = max(ans,it->second.second+1);
      }
      if(it->first == 0 && it->second.second== -1){
        ans = max(ans,it->second.first+1);
      }
      if(it->second.second==-1){
        continue;
      }
      else{
        ans = max(ans, it->second.second - it->second.first);
      }
    }
    return ans;
  }
};

int main() {
  int m;
  cin >> m;
  vector<int> array1(m);
  for (int i = 0; i < m; ++i) {
    cin >> array1[i];
  }
  Solution ob;
  cout << ob.maxLen(array1, m) << endl;

  return 0;
}
