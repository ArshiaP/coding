//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;

} * start;

void insert();
void display(struct Node *head);

struct Node *reverseList(struct Node *head) {
  if (head->next == NULL) {
    return head;
  }
  Node *prev = head;
  Node *curr = head->next;
  if (curr->next == NULL) {
    head->next = NULL;
    curr->next = head;
    return curr;
  }
  Node *next = curr->next;
  prev->next = NULL;

  while (next != NULL) {
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }
  curr->next = prev;
  return curr;
}

// proper code
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

int main() {
  start = NULL;
  insert();
  start = reverseList(start);
  display(start);
  printf("\n");
  return 0;
}

void insert() {
  int n, value, i;
  scanf("%d", &n);
  struct Node *temp;
  for (i = 0; i < n; i++) {
    scanf("%d", &value);
    if (i == 0) {
      start = (struct Node *)malloc(sizeof(struct Node));
      start->data = value;
      start->next = NULL;
      temp = start;
      continue;
    } else {
      temp->next = (struct Node *)malloc(sizeof(struct Node));
      temp = temp->next;
      temp->data = value;
      temp->next = NULL;
    }
  }
}

void display(struct Node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
}
