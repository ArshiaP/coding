//https://leetcode.com/problems/first-unique-character-in-a-string/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>


using namespace std;

int main(){
  string s = "loveleetcode";
  unordered_map<char,int>mp;
  for(int i=0;i<s.size();i++){
    mp[s[i]]++;
  }
  int min=-1;
  for(int i=0;i<s.size();i++){
    if(mp[s[i]]==1){
      min =i;
      break;
    }
    min=-1;
  }
  cout << min;
}

// int main(){
//   string s = "aabb";
//   unordered_map<char,pair<int,int>>mp;
//   for(int i=0;i<s.length();i++){
//     if(mp.count(s[i])){
//       mp[s[i]].second++;
//     }
//     else{
//       mp[s[i]].first=i;
//       mp[s[i]].second=1;
//     }
//   }
//   int minIndex=s.length();
//   for(auto it = mp.begin(); it!=mp.end();it++){
//     if(it->second.second==1){
//       minIndex = min(it->second.first, minIndex);
//     }
//   }
//   if(minIndex==s.length()){
//     minIndex=-1;
//   }
//   cout << minIndex;
// }