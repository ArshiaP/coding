// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include<set>

using namespace std;

int main()
{
  string s = "au";
  unordered_set<char> set;
  int i = 0;
  int j = 1;
  set.insert(s[i]);
  int count = 1;
  int best = 1;
  while (i < s.size() && j < s.size())
  {
    if (set.count(s[j]))
    {
      i++;
      j = i + 1;
      set.clear();
      set.insert(s[i]);
      best = max(best, count);
      count = 1;
    }
    else
    {
      count++;
      set.insert(s[j]);
      j++;
    }
  }
  best = max(best, count);
  if (s == "")
  {
    best = 0;
  }
  cout << best;
}

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.length();
    if (n <= 1)
      return n;
    set<char> st;
    int maxsize = 0;
    int i = 0, j = 0;
    while (j < n)
    {
      if (st.count(s[j]) == 0)
      {
        st.insert(s[j]);
        maxsize = max(maxsize, (int)st.size());
        j++;
      }
      else
      {
        st.erase(s[i]);
        i++;
      }
    }
    return maxsize;
  }
};

//the basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values, and keep two pointers which define the max substring. move the right pointer to scan through the string , and meanwhile update the hashmap. If the character is already in the hashmap, then move the left pointer to the right of the same character last found. Note that the two pointers can only move forward.

class Solution2{
  public:
    int lengthOfLongestSubstring(string s){
      if (s.length()==0) return 0;
      unordered_map<char,int>mp;
      int maximum = 0;
      int i = 0; //left pointer
      for(int j =0 ; j< s.size();j++){
        if(mp.find(s[j])!=mp.end()){
          i = max(i,mp[s[j]]+1); 
        }
        mp[s[j]] = j; //map has the character and the position of that char
        maximum =max(maximum,j-i+1);
      }
      return maximum;
    }
};