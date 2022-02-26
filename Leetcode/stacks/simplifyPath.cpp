// https://leetcode.com/problems/simplify-path/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  string path = "/../home/";
  string ans;
  stack<string> s;
  string res;
  int i = 0;
  for (; i < path.size(); i++)
  {
    if (path[i] == '/')
    {
      res = "";
      i++;
      while (path[i] != '/' && i < path.size())
      {
        res += path[i];
        i++;
      }
      i--;
      cout << res << endl;
      if (res == "" || res == ".")
      {
        continue;
      }
      else if (res == "..")
      {
        if (!s.empty())
        {
          s.pop();
        }
      }
      else
      {
        if (res.length() > 0)
        {
          s.push(res);
        }
      }
    }
  }
  if (s.empty())
  {
    ans = '/';
  }
  while (!s.empty())
  {
    ans = "/" + s.top() + ans;
    s.pop();
  }
  cout << ans;
}