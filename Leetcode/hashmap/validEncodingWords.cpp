// https://leetcode.com/problems/short-encoding-of-words/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
  vector<string> words{"time", "me", "bell"};
  unordered_set<string> set;
  int ans = 0;

  for (string word : words)
  {
    set.insert(word);
  }
  for (string word : words)
  {
    for (int i = 1; i < word.length(); i++)
    {
      //need to only check substring which go till the end as if a substring is found, the end of the substring should also have a hash character
      
      set.erase(word.substr(i)); 
    }
  }
  for (auto it = set.begin(); it != set.end(); it++)
  {
    ans += (*it).length() + 1; // 1 for the hash character
  }
  cout << ans;
}