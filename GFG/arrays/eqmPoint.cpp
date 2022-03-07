//https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int equilibriumPoint(long long a[], int n) {

  if(n==1){
    return 1;
  }
    
    for(int i = 1;i<n;i++){
      a[i] += a[i-1];
    }
    for(int i = 0; i<n;i++){
      if(a[i-1] == (a[n-1]-a[i])){
        return i+1;
      }
    }
    return -1;
}

int main(){
  long long a[] = {1};
  int n = 1;
  int ans = equilibriumPoint(a,n);
  cout<<ans<<endl;
}