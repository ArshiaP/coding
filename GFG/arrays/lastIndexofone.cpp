// https://practice.geeksforgeeks.org/problems/last-index-of-15847/1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int lastIndex(string s)
{
  for(int i = s.length()-1 ; i>=0;i--){
    if(s[i]=='1'){
      return i;
    }
  }
  return -1;
}

int main()
{
}