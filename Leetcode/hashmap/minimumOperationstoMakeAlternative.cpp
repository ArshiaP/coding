// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
  int minimumOperations(vector<int> &nums)
  {
    // stores number,frequency pair
    unordered_map<int, int> odd;
    unordered_map<int, int> even;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i % 2 == 0)
      {
        even[nums[i]]++;
      }
      else
      {
        odd[nums[i]]++;
      }
    }

    // find the first two numbers occurring maximum times in even places
    int freqEven1 = 0;
    int freqEven2 = 0;
    int even1 = 0;
    int even2 = 0;

    for (auto i : even)
    {
      if (freqEven1 <= i.second)
      {
        freqEven2 = freqEven1;
        even2 = even1;
        freqEven1 = i.second;
        even1 = i.first;
      }
      else if (freqEven2 <= i.second)
      {
        even2 = i.first;
        freqEven2 = i.second;
      }
    }

    // similary for odd
    int freqOdd1 = 0;
    int freqOdd2 = 0;
    int odd1 = 0;
    int odd2 = 0;

    for (auto i : odd)
    {
      if (freqOdd1 <= i.second)
      {
        freqOdd2 = freqOdd1;
        odd2 = odd1;
        freqOdd1 = i.second;
        odd1 = i.first;
      }
      else if (freqOdd2 <= i.second)
      {
        odd2 = i.first;
        freqOdd2 = i.second;
      }
    }

    //check if the numbers are equal
    if(even1!= odd1){
    return count = nums.size() - freqEven1 - freqOdd1;   
    } 
    else{
      count= min(nums.size() - freqEven1 -freqOdd2,nums.size() - freqOdd1 -freqEven2);
      cout<<freqEven2<<" "<<freqOdd2<<endl;
      return count;
    }
    
  }
};


int main()
{
  Solution s;
  vector<int> v{4,2,1,4,4,4,1,3,4,1,1,4,4};
  int ans = s.minimumOperations(v);
  cout << ans;
}

class Solution2
{
public:
  int minimumOperations(vector<int> &nums)
  {
    // stores number,frequency pair
    unordered_map<int, int> odd;
    unordered_map<int, int> even;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i % 2 == 0)
      {
        even[nums[i]]++;
      }
      else
      {
        odd[nums[i]]++;
      }
    }

    // find the number occurring maximum times in even and odd positions
    int maxFreqEven = 0;
    int maxFreqOdd = 0;
    int evenNum = 0;
    int oddNum = 0;
    bool flagOdd = true;
    bool flagEven = true;

    while (evenNum == oddNum)
    {
      if (flagEven)
      {
        for (auto i : even)
        {
          if (maxFreqEven < i.second)
          {
            evenNum = i.first;
            maxFreqEven = i.second;
          }
        }
      }
      if (flagOdd)
      {
        for (auto i : odd)
        {
          if (maxFreqOdd < i.second)
          {
            oddNum = i.first;
            maxFreqOdd = i.second;
          }
        }
      }
      if (evenNum == oddNum && maxFreqEven < maxFreqOdd)
      {
        even.erase(evenNum);
        flagOdd = false;
        maxFreqEven =0;
      }
      else if (evenNum == oddNum && maxFreqEven > maxFreqOdd)
      {
        odd.erase(evenNum);
        flagEven = false;
        maxFreqOdd =0;
      }
      else if (evenNum == oddNum && maxFreqEven == maxFreqOdd)
      {
        if (odd.size() > even.size() && odd.size() != 0)
        {
          odd.erase(evenNum);
          flagEven = false;
          maxFreqOdd = 0;
        }
        else if (even.size() > odd.size() && even.size() != 0)
        {
          even.erase(evenNum);
          flagOdd = false;
          maxFreqEven = 0;
        }
        else
        {
          return -1;
        }
      }else{
        continue;
      }
      if (odd.size() == 0 || even.size() == 0)
      {
        return -1;
      }
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (i % 2 == 0 && nums[i] != evenNum)
      {
        count++;
      }
      if (i % 2 == 1 && nums[i] != oddNum)
      {
        count++;
      }
    }
    return count;
  }
};