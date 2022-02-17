// https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
  string fractionToDecimal(int numerator, int denominator)
  {
    string ans = "";
    //keeps track of the remainder and its position in the string
    unordered_map<long,int> map; 
    if((numerator>0 && denominator <0 )||(numerator<0 && denominator >0 )){
      ans += '-';
    }
    long num = abs((long)numerator);
    long den = abs((long)denominator);
    if (num % den== 0 )
    {
        return ans += to_string(num / den);
    }
    ans += to_string(num / den) + '.';
    long rem = num%den;
    while(rem){
      if(map.find(rem)!= map.end()){
        //insert a '(' before the occurence of that rem
        ans.insert(ans.begin()+map[rem],'(');
        ans+=')';
        return ans;
      }
      map[rem] = ans.size(); 
      rem*=10;
      ans+=to_string(rem/den);
      rem = rem% den;
    }
    return ans;
  }
};

int main()
{
  int numerator = 1;
  int denominator = 6;

  Solution s;
  string ans = s.fractionToDecimal(numerator,denominator);
  cout<<ans<<endl;
  
}