// https://leetcode.com/problems/fruit-into-baskets/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
  vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};

  int x = 0;
  int best = 0;
  int current = 0;
  unordered_map<int, int> map;

  for (int i = 0; i < fruits.size(); i++)
  {
    if (map.count(fruits[i]) == 0 && map.size() < 2)
    {
      map[fruits[i]] = 1;
      current++;
    }
    else if (map.count(fruits[i]))
    {
      current++;
    }
    else if (map.count(fruits[i]) == 0 && map.size() == 2)
    {
      map.erase(fruits[x - 1]);
      map[fruits[i]] = 1;
      current = i - x + 1;
    }
    if (fruits[x] != fruits[i])
    {
      x = i;
    }
    best = max(best, current);
  }

  cout << best << endl;
}

class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    if (fruits.size() <= 2)
      return fruits.size();

    int i = 0;
    int j = 0;
    unordered_map<int, int> mp;
    int count = 0;
    while (j < fruits.size())
    {
      mp[fruits[j]]++;
      // Size of Map is less than 2
      if (mp.size() <= 2)
      {
        count = max(count, j - i + 1); // Incrementing the Maximum Length
        j++;
      }

      if (mp.size() > 2)
      {

        while (mp.size() > 2)
        {
          mp[fruits[i]]--;
          // If the size of ith fruit is 0 mean there is no need of that fruit and
          // we can remove from map
          if (mp[fruits[i]] == 0)
          {
            mp.erase(fruits[i]);
          }
          i++;
        }
        j++;
      }
    }

    return count;
  }
};