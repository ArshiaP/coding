// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void printList(Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  cout << endl;
}

class Solution {
 public:
  // Function to merge K sorted linked list.
  Node *mergeKLists(Node *arr[], int K) {
    Node* ll = new Node(-1);
    priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;

    for(int i=0;i<K;i++){
      pq.push(make_pair(arr[i]->data,arr[i]));
    }


    Node* ans = ll;
    while(!pq.empty()){
      Node* temp = new Node(pq.top().first);
      ll->next = temp;
      ll=ll->next;
      Node* pointer = pq.top().second;
      pointer=pointer->next;
      pq.pop();
      if(pointer!=NULL){
        pq.push({pointer->data,pointer});
      }
    }
    return ans->next;
  }
};

int main() {
  int N;
  cin >> N;
  struct Node *arr[N];
  for (int j = 0; j < N; j++) {
    int n;
    cin >> n;

    int x;
    cin >> x;
    arr[j] = new Node(x);
    Node *curr = arr[j];
    n--;

    for (int i = 0; i < n; i++) {
      cin >> x;
      Node *temp = new Node(x);
      curr->next = temp;
      curr = temp;
    }
  }
  Solution obj;
  Node *res = obj.mergeKLists(arr, N);
  printList(res);

  return 0;
}