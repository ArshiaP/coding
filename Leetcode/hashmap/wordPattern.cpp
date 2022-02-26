// https://leetcode.com/problems/word-pattern/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  string pattern = "abba";
  string s = "dog dog dog dog";

  unordered_map<char, string> map;
  unordered_set<string> set;

  int patInd = 0;
  int sInd = 0;

  while (patInd < pattern.length() && sInd < s.length()) {
    string word = "";
    while (s[sInd] != ' ' && sInd < s.length()) {
      word.push_back(s[sInd]);
      sInd++;
    }
    sInd++;
    if (map.count(pattern[patInd])) {
      if (map[pattern[patInd]] == word) {
      } else {
        cout << "false";
        break;
      }
    } else {
      if (set.count(word)) {
        cout << "false";
        break;
      } else {
        map[pattern[patInd]] = word;
        set.insert(word);
      }
    }
    patInd++;
  }

  if (patInd != pattern.length() || !(sInd > s.length())) {
    cout << "false" << endl;
  }
}