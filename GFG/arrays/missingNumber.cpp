//https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

class Solution{
  public:
  int MissingNumber(vector<int>& array, int n){
    int sum=0;
    for(int i =0;i<n;i++){
      sum+=array[i];
    }
    return ((n*(n + 1))/2) - sum;
  }
};