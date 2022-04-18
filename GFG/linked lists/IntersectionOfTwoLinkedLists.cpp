// https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1#

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};

Node* inputList(int size) {
  Node *head, *tail;
  int val;

  cin >> val;
  head = tail = new Node(val);

  while (--size) {
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
}

class Solution {
 public:
  Node* findIntersection(Node* head1, Node* head2) {
    unordered_set<int> set;
    Node* result = NULL;
    Node* ans;
    while (head2 != NULL) {
      set.insert(head2->data);
      head2 = head2->next;
    }
    while (head1 != NULL) {
      if (set.find(head1->data) != set.end()) {
        Node* temp = new Node(head1->data);
        if(result == NULL){
          result = temp;
          ans = result;
        }
        else{
          result->next = temp;
          result = result->next;
        }
      }
      head1 = head1->next;
    }
    return ans;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;

    cin >> n;
    Node* head1 = inputList(n);

    cin >> m;
    Node* head2 = inputList(m);
    Solution obj;
    Node* result = obj.findIntersection(head1, head2);

    printList(result);
    cout << endl;
  }
  return 0;
}