// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string reverseWords(string S)
{
  string ans;
  for (int i = 0; i < S.size(); i++)
  {
    string curr = "";
    while (S[i] != '.' && i != S.size())
    {
      curr += S[i];
      i++;
    }
    ans = curr + "." + ans;
  }
  ans.pop_back();
  return ans;
}

int main()
{
  string s = "i.like.this.program.very.much";
  string ans = reverseWords(s);
  cout << ans << endl;
}