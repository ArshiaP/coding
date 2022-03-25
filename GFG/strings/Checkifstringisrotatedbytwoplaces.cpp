//https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isRotated(string a, string b)
{
  if (a.length() == b.length() and a.length() <= 2)
  {
    if (a == b)
      return true;
    return false;
  }

  if(a.length()!=b.length()){
    return false;
  }

  bool flag=1;

  int i=0,j=2;
  for(; i<a.length(); i++,j++){
    if(j==b.length()){
      j=0;
    }
    if(a[i]!=b[j]){
      flag = 0;
      break;
    }
  }

  if(flag == 1){
    return true;
  }

  i=2,j=0;
  for(; j<b.length(); i++,j++){
    if(i==a.length()){
      i=0;
    }
    if(a[i]!=b[j]){
      return false;
    }
  }
  return true;
}

int main()
{
  string a = "geeksforgeeks";
  string b = "geeksgeeksfor";
  cout << isRotated(a, b) << endl;
}