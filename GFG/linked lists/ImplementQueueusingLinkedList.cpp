// { Driver Code Starts
#include <iostream>
using namespace std;

struct QueueNode {
  int data;
  QueueNode *next;
  QueueNode(int a) {
    data = a;
    next = NULL;
  }
};

struct MyQueue {
  QueueNode *front;
  QueueNode *rear;
  void push(int);
  int pop();
  MyQueue() { front = rear = NULL; }
};

int main() {
  int T;
  cin >> T;
  while (T--) {
    MyQueue *sq = new MyQueue();

    int Q;
    cin >> Q;
    while (Q--) {
      int QueryType = 0;
      cin >> QueryType;
      if (QueryType == 1) {
        int a;
        cin >> a;
        sq->push(a);
      } else if (QueryType == 2) {
        cout << sq->pop() << " ";
      }
    }
    cout << endl;
  }
}
// } Driver Code Ends

// Function to push an element into the queue.
void MyQueue::push(int x) {
  QueueNode *temp = new QueueNode(x);
  if (rear == NULL) {
    front = rear = temp;
  } else {
    rear->next = temp;
    rear = rear->next;
  }
}

// Function to pop front element from the queue.
int MyQueue ::pop() {
  if (front == NULL) {
    return -1;
  } else {
    QueueNode *temp = front;
    front = front->next;
    if (front == NULL) {
      rear = NULL;
    }
    int x = temp->data;
    delete temp;
    return x;
  }
}
