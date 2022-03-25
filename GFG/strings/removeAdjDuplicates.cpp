// https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string remove(string s)
{
  string res = "";
  int i = 0;
  while (i < s.size())
  {
    int freq = 1;
    while (i + 1 < s.size() and s[i] == s[i + 1])
    {
      freq++;
      i++;
    }
    if (freq == 1)
    {
      res.push_back(s[i]);
    }
    i++;
  }

  if (res == s)
    return res;

  return remove(res);
}

int main()
{
  string s = "abccbccbac";
  string ans = remove(s);
  cout << ans << endl;
}
