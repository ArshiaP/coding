// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
  int data;
  struct node* next;

  node(int x) {
    data = x;
    next = NULL;
  }
};

void printList(struct node* node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

class Solution {
 public:
  struct node* reverse(struct node* head, int k) {
    if (head == NULL) {
      return head;
    }
    node* prev = NULL;
    node* next = NULL;
    node* curr = head;
    int group = 0;
    while (curr != NULL and group < k) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      group++;
    }
    if (next != NULL) {
      head->next = reverse(next, k);
    }
    return prev;
  }
};

int main(void) {
  struct node* head = NULL;
  struct node* temp = NULL;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;
    if (i == 0) {
      head = new node(value);
      temp = head;
    } else {
      temp->next = new node(value);
      temp = temp->next;
    }
  }

  int k;
  cin >> k;

  Solution ob;
  head = ob.reverse(head, k);
  printList(head);

  return (0);
}
