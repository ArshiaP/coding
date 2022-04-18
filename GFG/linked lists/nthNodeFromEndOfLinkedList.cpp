// https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/
int main() {
  int i, n, l, k;

  struct Node *head = NULL, *tail = NULL;

  cin >> n >> k;
  int firstdata;
  cin >> firstdata;
  head = new Node(firstdata);
  tail = head;
  for (i = 1; i < n; i++) {
    cin >> l;
    tail->next = new Node(l);
    tail = tail->next;
  }

  cout << getNthFromLast(head, k) << endl;
  return 0;
}

int getNthFromLast(Node *head, int n) {
  int count = 0;
  Node *temp = head;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  count = count - n;
  if (count < 0) {
    return -1;
  }
  while (count--) {
    head = head->next;
  }
  return head->data;
}
