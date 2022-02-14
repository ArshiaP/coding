// https://leetcode.com/problems/assign-cookies/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> g{10, 9, 8, 7};
  vector<int> s{5, 6, 7, 8};
  int satisfiedChildren = 0;
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  int gind = 0;
  int sind = 0;

  while (gind != g.size() && sind != s.size())
  {
    if (g.at(gind) > s.at(sind))
    {
      sind++;
    }
    else if (g.at(gind) <= s.at(sind))
    {
      satisfiedChildren++;
      gind++;
      sind++;
    }
  }

  cout << satisfiedChildren;
}

