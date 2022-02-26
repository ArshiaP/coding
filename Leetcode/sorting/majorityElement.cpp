// https://leetcode.com/problems/majority-element/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> nums{2, 2, 1, 1, 1, 2, 2};

  sort(nums.begin(), nums.end());

  int count = 0;
  int current = nums.at(0);
  int best = 0;
  int ans = nums.at(0);

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums.at(i) != current)
    {
      current = nums.at(i);
      // count = 0;
      // count++;
      count = 1;
      best = max(count, best);
    }
    else
    {
      count++;
      if(count>best){
        ans = nums.at(i);
      }
      best = max(count, best);
    }
  }

  cout<< ans;
}