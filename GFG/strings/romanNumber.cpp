// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int romanToDecimal(string &s)
{
  unordered_map<char,int>map{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
  int ans = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if(i+1<s.size() && map[s[i]] < map[s[i+1]]){
      ans = ans + map[s[i+1]] - map[s[i]];
      i++;
    }
    else{
      ans+=map[s[i]];
    }
  }
  return ans;
}

int main()
{
  string s = "XLIX";
  cout << romanToDecimal(s) << endl;
}