// https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getMiddle(Node* head) {
  struct Node* temp = head;
  int count = 0;
  while(temp!=NULL){
    temp = temp->next;
    count++;
  }
  cout<<count<<endl;
  count/=2;
  while(count--){
    head=head->next;
  }
  return head->data;
}

int main() {
  int N;
  cin >> N; //no.of elements
  int data;
  cin >> data; //first value of ll
  struct Node* head = new Node(data);
  struct Node* tail = head;

  //next n-1 values
  for (int i = 0; i < N - 1; ++i) {
    cin >> data;
    tail->next = new Node(data);
    tail = tail->next;
  }

  cout << getMiddle(head) << endl;
  return 0;
}