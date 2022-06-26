// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1#
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

// Function to Build Tree
Node *buildTree(string str) {
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = new Node(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size()) {
    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current Node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N") {
      // Create the left child for the current Node
      currNode->left = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N") {
      // Create the right child for the current Node
      currNode->right = new Node(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

class Solution {
 public:
  // Function to serialize a tree and return a list containing nodes of tree.
  vector<int> serialize(Node *root) {
    vector<int> ans;
    if (root == NULL) {
      return ans;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        Node *temp = q.front();
        q.pop();
        if (temp) {
          ans.push_back(temp->data);
          q.push(temp->left);
          q.push(temp->right);
        } else {
          ans.push_back(0);
        }
      }
    }
    return ans;
  }

  // Function to deserialize a list and construct the tree.
  Node *deSerialize(vector<int> &arr) {
    if (arr.empty()) {
      return NULL;
    }

    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int i = 1;  // pointer for array

    while (!q.empty()) {
      Node *temp = q.front();
      q.pop();
      if (temp) {
        Node *left = arr[i] ? new Node(arr[i]) : NULL;
        i++;
        Node *right = arr[i] ? new Node(arr[i]) : NULL;
        i++;
        temp->left = left;
        q.push(left);
        temp->right = right;
        q.push(right);
      } else {
        continue;
      }
    }

    return root;
  }
};

// { Driver Code Starts.

void inorder(Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void _deleteTree(Node *node) {
  if (node == NULL) return;

  /* first delete both subtrees */
  _deleteTree(node->left);
  _deleteTree(node->right);

  /* then delete the node */
  // cout << "Deleting node: " << node->data << endl;
  delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
  _deleteTree(*node_ref);
  *node_ref = NULL;
}

int main() {
  string treeString;
  getline(cin, treeString);
  Node *root = buildTree(treeString);

  Solution serial, deserial;
  vector<int> A = serial.serialize(root);
  deleteTree(&root);
  Node *getRoot = deserial.deSerialize(A);
  inorder(getRoot);
  cout << "\n";

  return 0;
}  // } Driver Code Ends