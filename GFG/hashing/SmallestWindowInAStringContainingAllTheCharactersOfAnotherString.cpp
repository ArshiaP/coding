// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string smallestWindow(string s, string p) {
    if (p.length() == 0) return "";
    if (s.length() < p.length()) return "-1";

    unordered_map<char, int> patMap;
    unordered_map<char, int> windowMap;
    for (auto c : p) {
      patMap[c]++;
    }

    int count = patMap.size();
    int right = 0, left = 0;
    int minSize = INT_MAX;
    int minLeft = -1;
    int currCount = 0;

    while (right < s.size()) {
      if (patMap.find(s[right]) != patMap.end()) {
        windowMap[s[right]]++;
        if (windowMap[s[right]] == patMap[s[right]]) {
          currCount++;
          if (currCount == count) {
            while (currCount == count) {
              if (patMap.find(s[left]) != patMap.end()) {
                windowMap[s[left]]--;
                if (windowMap[s[left]] < patMap[s[left]]) {
                  currCount--;
                }
              }
              left++;
            }
            if (minSize > right - left + 2) {
              minSize = right - left + 2;
              minLeft = left - 1;
            }
          }
        }
      }
      right++;
    }

    if (minLeft != -1) {
      return s.substr(minLeft, minSize);
    }
    return "-1";
  }
};

int main() {
  string s;
  cin >> s;
  string pat;
  cin >> pat;
  Solution obj;
  cout << obj.smallestWindow(s, pat) << endl;

  return 0;
}