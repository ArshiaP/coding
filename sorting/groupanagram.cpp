//https://leetcode.com/problems/group-anagrams/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  vector<string> strs{"eat","tea","tan","ate","nat","bat"};
  priority_queue<pair<string,string>> pq;
  vector<vector<string>> ans;
  string st;
  vector<string>a;
  string curr = "", prev = "";
  for(string s: strs){
    st = s;
    sort(st.begin(),st.end());
    pq.push(make_pair(st,s));
  }

  while(!pq.empty()){
    prev = curr;
    curr=pq.top().first;
    
    if(prev == curr){
      a.push_back(pq.top().second);
    }
    else{
      if(!a.empty()){
        ans.push_back(a);
      }
      a = {pq.top().second};
      
    }
    pq.pop();
  }
  ans.push_back(a);

  for(vector<string> vec: ans){
    for(string x: vec){
      cout << x << " ";
    }
    cout << endl;
  }
}