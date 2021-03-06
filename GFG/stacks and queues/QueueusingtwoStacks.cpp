//https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1
#include <bits/stdc++.h>

using namespace std;

class StackQueue {
 private:
  stack<int> s1;
  stack<int> s2;

 public:
  void push(int B);
  int pop();
};
int main() {
  StackQueue *sq = new StackQueue();

  int Q;
  cin >> Q;
  while (Q--) {
    int QueryType = 0;
    cin >> QueryType;
    if (QueryType == 1) {
      int a;
      cin >> a;
      sq->push(a);
    } else if (QueryType == 2) {
      cout << sq->pop() << " ";
    }
  }
  cout << endl;
}

// Function to push an element in queue by using 2 stacks.
void StackQueue ::push(int x) {
  s1.push(x);
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop() {
  if(s1.empty() and s2.empty()){
    return -1;
  }
  if (s2.empty()) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }
  int x = s2.top();
  s2.pop();
  return x;
}
