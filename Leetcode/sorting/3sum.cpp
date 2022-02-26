//https://leetcode.com/problems/3sum/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
  vector<int> nums{-1,0,1,2,-1,-4};
  sort(nums.begin(),nums.end());
  int fixed;
  int i,j;
  int sum;
  vector<vector<int>> ans;
  for(fixed=0; fixed<nums.size();fixed++){
    if(fixed>0 && nums[fixed] == nums[fixed-1]){
      continue;
    }
    i=fixed+1;
    j=nums.size()-1;
    while(i<j){
      sum = nums[i] + nums[j];
      if(sum == -(nums[fixed])){
        vector<int> a{nums[fixed], nums[i], nums[j]};
        ans.push_back(a);
        i++;
        while(i<j && nums[i]==nums[i-1]){
          i++;
        }
      }
      else if(sum<(-nums[fixed])){
        i++;
      }
      else{
        j--;
      }
    }
    

    }
  
  for(vector<int> vec: ans){
    for(int x: vec){
      cout << x << " ";
    }
  }

}

//three pointer