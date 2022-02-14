#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  vector <int> nums{1,2,2,3};
  sort(nums.begin(), nums.end());
  int count = 0;
  int i = nums.size()-1;
  int largest = nums.back();
  while(count<2 && i>0){
    if(nums.at(i)==nums.at(i-1)){
      i--;
    }
    else{
      count++;
      i--;
    }
  }
  if(count==2){
    cout << nums.at(i);
  }
  else{
    cout << largest;
  }
}