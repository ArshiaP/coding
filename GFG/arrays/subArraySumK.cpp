// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include<set>

using namespace std;

class Solution
{
public:
  vector<int> subarraySum(int arr[], int n, long long s)
  {
    long long sum = 0;
    int first = 0;
    int last;
    vector<int> result;
    for (last = 0; last < n; last++)
    {
      sum += arr[last];

      if (sum >= s)
      {
        while (first < last && sum > s)
        {
          sum -= arr[first];

          first++;
        }

        if (sum == s)
        {
          result = {first + 1, last + 1};

          return result;
        }
      }
    }
    result.push_back(-1);
    return result;
  }


//https://leetcode.com/problems/subarray-sum-equals-k/
  int subarraySum(vector<int> &nums, int k)
  {
    unordered_multiset<int>set;
    int sum=0;
    int count = 0;
    for(auto it= nums.begin();it!=nums.end();it++){
      sum+= *it;
      if(set.count(sum-k)!=-1){
        count+=set.count(sum-k);
      }
      if(sum == k){
        count++;
      }
      set.insert(sum);
    }
    return count;
  }
};


//https://leetcode.com/problems/subarray-sum-equals-k/

class Solution2{
  public:
  int subarraySum(vector<int> &nums, int k){

    //v{2,3,0,4,3} k=7   
    unordered_map<int,int>map; //prefix Sum, number of times the sum occurs
    int count = 0;
    int sum = 0;
    for(int i = 0;i<nums.size();i++){
      sum += nums[i];
      if(map.find(sum-k)!= map.end()){
        count += map[sum-k];
      }
      if(sum == k){
        count++;
      }
      map[sum]++;
    }
    return count;
  }
};

int main()
{
  Solution s;
  Solution2 s2;
  int arr[] = {1, 2, 3, 7, 5};
  vector<int>nums {1,2,3};
  int n = 5;
  int sum = 3;
  int r = s.subarraySum(nums,sum);
  int ans  = s2.subarraySum(nums,sum);
  cout<<ans;
}
