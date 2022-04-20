// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool ispar(string x) {
  stack<char> st;
  for (char i : x) {
    if (i == '{' or i == '[' or i == '(') {
      st.push(i);
    } else if (i == '}' or i == ']' or i == ')') {
      if (st.empty()) {
        return false;
      } else {
        char c = st.top();
        st.pop();
        if ((c == '{' and i == '}') or (c == '[' and i == ']') or (c == '(' and i == ')')) {
          continue;
        } else {
          return false;
        }
      }
    } else {
      continue;
    }
  }

  if (!st.empty()) {
    return false;
  }

  return true;
}

int main() {
  string x = "{([]}";
  cout << ispar(x) << endl;
}