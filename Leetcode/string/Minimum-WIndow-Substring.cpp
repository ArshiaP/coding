// https://leetcode.com/problems/minimum-window-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }
    unordered_map<char, int> pat;
    unordered_map<char, int> text;
    for (int i = 0; i < t.size(); i++) {
      pat[t[i]]++;
    }
    int len = t.size();
    int count = 0;
    int startIdx = 0;
    int minLength = INT_MAX;
    int minStart = 0;
    for (int i = 0; i < s.size(); i++) {
      text[s[i]]++;
      if (pat.find(s[i]) != pat.end() && text[s[i]] <= pat[s[i]]) {
        count++;
      }
      if (count == len) {
        while (pat.find(s[startIdx]) == pat.end() || pat[s[startIdx]] < text[s[startIdx]]) {
          if (pat[s[startIdx]] < text[s[startIdx]]) {
            text[s[startIdx]]--;
          }
          startIdx++;
        }
        int curr = i - startIdx + 1;
        if (curr < minLength) {
          minStart = startIdx;
          minLength = curr;
        }
      }
    }
    return count == len ? s.substr(minStart, minLength) : "";
  }
};

int main() {
  string s = "ADOBECODEBANC", t = "ABC";
  Solution o;
  cout << o.minWindow(s, t) << endl;
}