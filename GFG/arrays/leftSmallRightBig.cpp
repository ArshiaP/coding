//https://practice.geeksforgeeks.org/problems/unsorted-array4925/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

//works for arrays with distinct elements
int findElement(int arr[], int n) {
    int temp [n];
    for(int i =0;i<n;i++){
      temp[i] = arr[i];
    }
    sort(temp,temp+n);
    for(int i = 1 ;i < n-1;i++){
      if(arr[i] == temp [i]){
        return temp[i];
      }
    }
    return -1;
}

//left[] keeps a track of the maximum number to the left of an element
//right[] keeps a track of the minimum number to the right of an element
//if arr[i] > left[i] && arr[i]<right[i] WORKS
int findElement(int arr[], int n) {
  int leftMax[n];
  int rightMin[n];

  int possible = INT_MIN;
  for(int i = 0;i < n ; i++){
    possible = max(possible,arr[i]);
    leftMax[i] = possible;
  }

  possible = INT_MAX;
  for(int i = n-1;i>=0;i--){
    possible = min(possible,arr[i]);
    rightMin[i] = possible;
  }

  //array running from index 1 to n-2(first and last element cant be the answer)
  for(int i = 1 ; i< n-1;i++){
    if(arr[i]>=leftMax[i] && arr[i]<=rightMin[i]){
      return arr[i];
    }
  }
  return -1;
}

//Shreyas' solution
int findElement(int arr[], int n) {
  int index = 0;
  int first = arr[0];
  bool solution = false;
  for (int i = 1; i < n; i++) {
    if (arr[i] < first) {
      solution = false;
    } else if (arr[i] >= first && solution == false) {
      solution = true;
      index = i;
      first = arr[i];
    }
  }

  if (index != 0 && index != n - 1 && solution == true) {
    return first;
  } else
    return -1;
}

int main(){
  int arr[] = {11,9,12};
  int ans = findElement(arr,3);
  cout<<ans;
}