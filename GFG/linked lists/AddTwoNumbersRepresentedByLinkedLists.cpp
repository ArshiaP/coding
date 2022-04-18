// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

struct Node* buildList(int size) {
  int val;
  cin >> val;

  Node* head = new Node(val);
  Node* tail = head;

  for (int i = 0; i < size - 1; i++) {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }

  return head;
}

void printList(Node* n) {
  while (n) {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

class Solution {
 public:
  struct Node* reverseList(struct Node* head) {
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  struct Node* addTwoLists(struct Node* first, struct Node* second) {
    first = reverseList(first);
    second = reverseList(second);
    Node* result = NULL;
    Node* ans;
    Node* temp;
    int val = 0;
    int carry = 0;
    while (first and second) {
      val = first->data + second->data + carry;
      carry = 0;
      if (val > 9) {
        carry = 1;
        val %= 10;
      }
      temp = new Node(val);
      if (result == NULL) {
        result = temp;
        ans = result;
      } else {
        result->next = temp;
        result = result->next;
      }
      first = first->next;
      second = second->next;
    }
    while (first) {
      val = first->data + carry;
      carry = 0;
      if (val > 9) {
        carry = 1;
        val %= 10;
      }
      result->next = new Node(val);
      result = result->next;
      first = first->next;
    }
    while (second) {
      val = second->data + carry;
      carry = 0;
      if (val > 9) {
        carry = 1;
        val %= 10;
      }
      result->next = new Node(val);
      result = result->next;
      second = second->next;
    }
    if (carry) {
      result->next = new Node(carry);
    }
    ans = reverseList(ans);
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;

    cin >> n;
    Node* first = buildList(n);

    cin >> m;
    Node* second = buildList(m);
    Solution ob;
    Node* res = ob.addTwoLists(first, second);
    printList(res);
  }
  return 0;
}