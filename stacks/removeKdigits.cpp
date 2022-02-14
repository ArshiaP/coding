// https://leetcode.com/problems/remove-k-digits/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <regex>
#include <unordered_map>


using namespace std;

int main()
{
  string num = "10";
  int k = 2;
  string res;
  int n = num.size();
  stack<char> st;
  st.push(num[0]);
  if (n == k)
  {
    res = "0";
  }
  else
  {
    for (int i = 1; i < n; i++)
    {
      while (!st.empty() && k > 0 && st.top() > num[i])
      {
        st.pop();
        k--;
      }

      if (st.empty() && num[i] == '0')
        continue;
      st.push(num[i]);
    }
    while (!st.empty() && k > 0)
    {
      st.pop();
      k--;
    }
    if (st.empty())
    {
      res = "0";
    }
    else
    {
      res = "";
      while (!st.empty())
      {
        res += st.top();
        st.pop();
      }
    }
    reverse(res.begin(), res.end());
  }
  cout << res;
}

//Logic - left to right. if num[i] is less than s.top, pop till it's greater or equal to. then push num[i] to stack.



// int main(){
//   string num = "10001";
//   int k =4;
//   string ans = "";
//   stack<char>s;
//   s.push(num[0]);
//   int i =1;
//   if( k == num.size()){
//     ans='0';
//   }
//   else{
//   while(i<num.size()&& k >0){
//     if(num[i]>=s.top()&& s.top()!='0'){
//       k--;
//     }
//     else if(num[i]>s.top()&& s.top()=='0' && i!=num.size()-1){
//       s.pop();
//       s.push(num[i]);  
//     }
//      else if(num[i]>s.top()&& s.top()=='0' && i==num.size()-1){
//      k--; 
//     }
//     else if(num[i]==s.top()){
//       s.push(num[i]);
//     }
//     else{
//       s.pop();
//       s.push(num[i]);
//       k--;
//     }
//      i++;
//   }
  
//   cout << i<<endl;
//   while(!s.empty()){
//     ans = s.top() + ans;
//     s.pop();
//   }
//   for(;i<num.size();i++){
//     ans+= num[i];
//   }
// }
//   const regex pattern("^0+(?!$)");
//   ans = regex_replace(ans, pattern, "");
//   cout << ans;
// }


  


