// https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1#
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
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

class Solution {
 public:
  Node* pairWiseSwap(struct Node* head) {
    Node* first = head;
    Node* second = first->next;
    if(second==NULL){
      return head;
    }
    head = second;
    Node* third = second->next;
    while(1){
      second->next=first;
      if(!third or !(third->next)){
        first->next = third ? third : NULL;
        return head;
      }
      first->next = third->next;
      first = third;
      second = first->next;
      third = second->next;
    }
  }
};

void printList(Node* node) {
  while (node != NULL) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int data;
    cin >> data;
    struct Node* head = new Node(data);
    struct Node* tail = head;
    map<Node*, int> mp;
    mp[head] = head->data;
    for (int i = 0; i < n - 1; ++i) {
      cin >> data;
      tail->next = new Node(data);
      tail = tail->next;
      mp[tail] = tail->data;
    }
    struct Node* failure = new Node(-1);
    Solution ob;
    head = ob.pairWiseSwap(head);
    int flag = 0;
    struct Node* temp = head;
    while (temp) {
      if (mp[temp] != temp->data) {
        flag = 1;
        break;
      }
      temp = temp->next;
    }
    if (flag)
      printList(failure);
    else
      printList(head);
  }
  return 0;
}