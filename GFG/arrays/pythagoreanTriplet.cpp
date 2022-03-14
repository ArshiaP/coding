//https://practice.geeksforgeeks.org/problems/pythagorean-triplet3018/1

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

bool checkTriplet(int arr[], int n) {
	    sort(arr,arr+n);
      int i ;
      int k = n-1;
      int j;
      int sum;
      for(;k>1;k--){
        sum = pow(arr[k],2);
        i=0;
        j = k-1;
        while(i<j){
          if(pow(arr[i],2) + pow(arr[j],2)==sum){
            return true;
          }
          else if(pow(arr[i],2) + pow(arr[j],2)>sum){
            j--;
          }
          else{
            i++;
          }
        }
      }
      return false;
	}

  int main(){
    int arr[] = {3, 2, 4, 6, 5};
    cout<<checkTriplet(arr,5)<<endl;
  }