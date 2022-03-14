// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long trappingWater(int arr[], int n) {
  long long ans = 0;
  int maximum = INT_MIN;
  int left[n], right[n];

  //keeps track of the maximum height of the block to the left of an element
  for (int i = 0; i < n; i++) {
    maximum = max(maximum, arr[i]);
    left[i] = maximum;
  }
  maximum = INT_MIN;

  //keeps track of the maximum height of the block to the right of an element
  for (int i = n - 1; i >= 0; i--) {
    maximum = max(maximum, arr[i]);
    right[i] = maximum;
  }

  //water trapped for each block
  for (int i = 0; i < n; i++) {
    ans += min(left[i], right[i]) - arr[i];
  }

  return ans;
}

int main()
{
  int arr[] = {3,0,0,2,0,4};
  long long ans = trappingWater(arr,6);
  cout<<ans<<endl; 
}