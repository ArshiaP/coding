// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
 public:
  //***********************************************//
  struct Node *reverseList(struct Node *head) {
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  bool isPalindrome(Node *head) {
    int n = 0;
    Node *temp = head;
    while (temp != NULL) {
      n++;
      temp = temp->next;
    }
    temp = head;
    int count = n / 2;
    while (count--) {
      temp = temp->next;
    }
    temp = reverseList(temp);
    while (temp != NULL) {
      if (head->data != temp->data) {
        return false;
      }
      head = head->next;
      temp = temp->next;
    }
    return true;
  }

  //***********************************************//

  Node *left;
  bool recursion(Node *right) {
    if (right == NULL) {
      return true;
    }
    bool ans = recursion(right->next);
    if (ans == false) {
      return false;
    }
    if (left->data == right->data) {
      left = left->next;
      return true;
    } else {
      return false;
    }
  }
  bool isPalindrome(Node *head) {
    left = head;
    return recursion(head);
  }
};

int main() {
  int T, i, n, l, firstdata;
  cin >> T;
  while (T--) {
    struct Node *head = NULL, *tail = NULL;
    cin >> n;
    // taking first data of LL
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for (i = 1; i < n; i++) {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }
    Solution obj;
    cout << obj.isPalindrome(head) << endl;
  }
  return 0;
}

// } Driver Code Ends