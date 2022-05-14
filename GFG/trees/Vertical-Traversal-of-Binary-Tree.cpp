// https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
  int data;
  Node* left;
  Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
  Node* temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

vector<int> verticalOrder(Node* root);

// Function to Build Tree
Node* buildTree(string str) {
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
  Node* root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node*> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size()) {
    // Get and remove the front of the queue
    Node* currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N") {
      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

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
      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

class Solution {
 public:
  vector<int> verticalOrder(Node* root) {
    vector<int> ans;
    if (root == NULL) {
      return ans;
    }
    unordered_map<int, vector<int>> map;
    queue<pair<Node*, int>> q;
    int min = 0;
    int max = 0;
    q.push({root, 0});
    while (!q.empty()) {
      auto element = q.front();
      q.pop();
      Node* node = element.first;
      int horiDist = element.second;
      if (min > horiDist) min = horiDist;
      if (max < horiDist) max = horiDist;
      map[horiDist].push_back(node->data);
      if (node->left) {
        q.push({node->left, (horiDist - 1)});
      }
      if (node->right) {
        q.push({node->right, (horiDist + 1)});
      }
    }
    for (int i = min; i <= max; i++) {
      for (int j = 0; j < map[i].size(); j++) {
        ans.push_back(map[i][j]);
      }
    }
    return ans;
  }
};

int main() {
  string s, ch;
  getline(cin, s);
  Node* root = buildTree(s);
  Solution ob;
  vector<int> res = ob.verticalOrder(root);
  for (int i : res) cout << i << " ";
  cout << endl;
  return 0;
}

// } Driver Code Ends


/*
explanation:

1. To maintain a hash for the branch of each node.

2. Traverse the tree in level order fashion.

3. In level order traversal, maintain a queue

   which holds, node and its vertical branch.

    * pop from queue.

    * add this node's data in vector corresponding

      to its branch in the hash.

    * if this node hash left child, insert in the 

      queue, left with branch - 1.

    * if this node hash right child, insert in the 

      queue, right with branch + 1.
*/