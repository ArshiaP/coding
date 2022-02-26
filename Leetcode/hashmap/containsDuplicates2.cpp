//https://leetcode.com/problems/contains-duplicate-ii/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>map; //value,index
        for(int i = 0;i<nums.size();i ++){
          if(map.find(nums[i])==map.end()){
            map[nums[i]] = i;
          }
          else{
            if(i-map[nums[i]]<=k){
              return true;
            }
            else{
              map[nums[i]] = i;
            }
          }
        }
        return false;
    }
};



class Solution2{
  public:
   bool containsNearbyDuplicate(vector<int>& nums, int k) {
     unordered_set<int>set;
     for(int i = 0;i<nums.size();i++){
       if(i>k){
         set.erase(nums[i-k-1]);
       }
       if(set.find(nums[i])!=set.end()){
         return true;
       }
       set.insert(nums[i]);
     }
     return false;
   }
};
int main(){
  Solution2 s;
  vector<int>n{1,2,3,1,2,3};
  int k = 2;
  cout << s.containsNearbyDuplicate(n,k);
}