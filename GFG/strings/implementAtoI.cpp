// https://practice.geeksforgeeks.org/problems/implement-atoi/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int atoi(string s) {
  int ans = 0;
  int digit = 0;
  int i = 0;
  int flag = 0;
  if (s[0] == '-' and s.length() != 1) {
    i++;
    flag = 1;
  }
  for (i; i < s.length(); i++) {
    digit = s[i] - 0 - 48;
    if (digit < 10 and digit >= 0) {
      ans = ans * 10 + digit;
    } else
      return -1;
  }
  return flag ? -ans : ans;
}

int main() {
  string s = "-21";
  cout << atoi(s) << endl;
}