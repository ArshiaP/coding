// https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *rotate(Node *head, int k) {
  Node *last = head;
  Node *next = head;
  while(last->next!=NULL){
    last = last->next;
  }
  while(k--){
    next = head->next;
    last->next=head;
    head->next=NULL;
    last = last->next;
    head=next;
  }
  return head;
 }

class Solution {
 public:
  // Function to rotate a linked list.
  Node *rotate(Node *head, int k) {
    Node *curr = head;
    Node *prev = NULL;
    for (int i = 0; i < k; i++) {
      prev = curr;
      curr = curr->next;
    }
    if (curr == NULL or prev == NULL) {
      return head;
    }
    Node *toBeReturned = curr;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = head;
    prev->next = NULL;
    return toBeReturned;
  }
};

void printList(Node *n) {
  while (n != NULL) {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

int main() {
  int n, val, k;
  cin >> n;

  cin >> val;
  Node *head = new Node(val);
  Node *tail = head;

  for (int i = 0; i < n - 1; i++) {
    cin >> val;
    tail->next = new Node(val);
    tail = tail->next;
  }

  cin >> k;

  Solution ob;
  head = rotate(head, k);
  printList(head);
  return 1;
}