// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

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

struct Node *start = NULL;

class Solution {
 public:
  // Function to sort a linked list of 0s, 1s and 2s.
  Node *segregate(Node *head) {
    Node *ans = new Node(10);
    Node *zero = NULL;
    Node *one = NULL;
    Node *two = NULL;
    Node *zeroFirst = NULL;
    Node *oneFirst = NULL;
    Node *twoFirst = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr) {
      next = curr->next;
      if (curr->data == 0) {
        if (zero == NULL) {
          zeroFirst = curr;
          zero = curr;
          curr->next = NULL;
        } else {
          zero->next = curr;
          curr->next = NULL;
          zero = zero->next;
        }
      } else if (curr->data == 1) {
        if (one == NULL) {
          oneFirst = curr;
          one = curr;
          curr->next = NULL;
        } else {
          one->next = curr;
          curr->next = NULL;
          one = one->next;
        }
      } else {
        if (two == NULL) {
          twoFirst = curr;
          two = curr;
          curr->next = NULL;
        } else {
          two->next = curr;
          curr->next = NULL;
          two = two->next;
        }
      }
      curr = next;
    }
    Node *last = ans;
    if (zeroFirst != NULL) {
      last->next = zeroFirst;
      last = zero;
    }
    if (oneFirst != NULL) {
      last->next = oneFirst;
      last = one;
    }
    if (twoFirst != NULL) {
      last->next = twoFirst;
      last = two;
    }
    last->next = NULL;
    Node *temp = ans;
    ans = ans->next;
    delete temp;
    return ans;
  }
};

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
  while (Node != NULL) {
    printf("%d ", Node->data);
    Node = Node->next;
  }
  printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
  int n, value, i;
  // scanf("%d",&n);
  n = n1;
  struct Node *temp;
  for (i = 0; i < n; i++) {
    scanf("%d", &value);

    if (i == 0) {
      start = new Node(value);
      temp = start;
      continue;
    } else {
      temp->next = new Node(value);
      temp = temp->next;
      temp->next = NULL;
    }
  }
}

int main() {
  int n;

  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);

    insert(n);
    Solution ob;
    struct Node *newHead = ob.segregate(start);
    printList(newHead);
  }

  return 0;
}  // } Driver Code Ends