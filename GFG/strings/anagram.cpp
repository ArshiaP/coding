// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool isAnagram(string a, string b) {
  if (a.size() != b.size()) {
    return false;
  }
  unordered_map<char, int> map;
  for (int i = 0; i < a.length(); i++) {
    map[a[i]]++;
  }
  for (int i = 0; i < a.length(); i++) {
    if (map.find(b[i]) == map.end()) {
      return false;
    }
    map[b[i]]--;
    if (map[b[i]] < 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string a = "allergy";
  string b = "allergic";
  cout << isAnagram(a, b) << endl;
}