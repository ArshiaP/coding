// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// { Driver Code Starts

/* Link list Node */
struct Node {
  int data;
  struct Node* next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size) {
  if (size == 0) return NULL;

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

/* Driver program to test above function*/
int main() {
  int n1, n2, n3;

  cin >> n1 >> n2 >> n3;

  Node* head1 = inputList(n1);
  Node* head2 = inputList(n2);
  Node* common = inputList(n3);

  Node* temp = head1;
  while (temp != NULL && temp->next != NULL)
    temp = temp->next;
  if (temp != NULL) temp->next = common;

  temp = head2;
  while (temp != NULL && temp->next != NULL)
    temp = temp->next;
  if (temp != NULL) temp->next = common;

  cout << intersectPoint(head1, head2) << endl;

  return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2) {
  int len1=0, len2=0;
  Node* temp = head1;
  while (temp != NULL) {
    len1++;
    temp = temp->next;
  }

  temp = head2;
  while (temp != NULL) {
    len2++;
    temp = temp->next;
  }

  if (len1 > len2) {
    for (int i = 0; i < abs(len1 - len2); i++) {
      head1 = head1->next;
    }
  } else {
    for (int i = 0; i < abs(len1 - len2); i++) {
      head2 = head2->next;
    }
  }

  while(head1!=head2){
    head1 = head1->next;
    head2 = head2->next;
  }

  return head1->data;
}
