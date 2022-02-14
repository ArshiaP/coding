//https://leetcode.com/problems/make-the-string-great/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
  string s = "leEeetcode";
  string ans = "";
  stack<char> st;
  int i =0;
  for(char x: s){
    if(st.empty()){
      st.push(x);
    }
    else{
      //checking if lowercase same but char not same
      if(tolower(x)==tolower(st.top()) && x!=st.top()){
        st.pop();
      }
      else{
        st.push(x);
      }
    }
  }
  while(!st.empty()){
    ans = st.top() + ans;
    st.pop();
  }
  cout << ans ;
}