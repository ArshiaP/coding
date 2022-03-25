// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(string arr[], int n) {
  string ans;
  int i = 0;
  while (true) {
    char currentChar = arr[0][i];
    for (int j = 0; j < n; j++) {
      if (arr[j].length() == i) {
        return ans.length() ? ans : "-1";
      } else if (arr[j][i] == currentChar) {
        continue;
      } else {
        return ans.length() ? ans : "-1";
      }
    }
    ans.push_back(currentChar);
    i++;
  }
  return ans.length() ? ans : "-1";
}

int main() {
  string s[] = {"geeksforgeeks", "geeks", "geek",
                "geezer"};
  cout << longestCommonPrefix(s, 4) << endl;
}