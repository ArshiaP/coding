// https://leetcode.com/problems/assign-cookies/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  vector<int> g{1,2};
  vector<int> s{1,2,3};

  sort(g.begin(),g.end());
  sort(s.begin(),s.end());
  int i=0;
  int j=0;
  while(i<g.size() && j<s.size()){
    if(g[i]<=s[j]){
      i++;
      j++;
    }
    else{
      j++;
    }
  }
  cout << i;
}