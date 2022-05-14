// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1#

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

vector<int> bottomView(Node* root);

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
  vector<int> bottomView(Node* root) {
    vector<int> ans;
    if (root == NULL) {
      return ans;
    }
    unordered_map<int, int> map;
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
      map[horiDist] = node->data;
      if (node->left) {
        q.push({node->left, (horiDist - 1)});
      }
      if (node->right) {
        q.push({node->right, (horiDist + 1)});
      }
    }
    for (int i = min; i <= max; i++) {
      ans.push_back(map[i]);
    }
    return ans;
  }
};

int main() {
  string s, ch;
  getline(cin, s);
  Node* root = buildTree(s);
  Solution ob;
  vector<int> res = ob.bottomView(root);
  for (int i : res) cout << i << " ";
  cout << endl;
  return 0;
}

// } Driver Code Ends

/*
Method 1 - Using Queue 
The following are steps to print Bottom View of Binary Tree. 
1. We put tree nodes in a queue for the level order traversal. 
2. Start with the horizontal distance(hd) 0 of the root node, keep on adding left child to queue along with the horizontal distance as hd-1 and right child as hd+1. 
3. Also, use a TreeMap which stores key value pair sorted on key. 
4. Every time, we encounter a new horizontal distance or an existing horizontal distance put the node data for the horizontal distance as key. For the first time it will add to the map, next time it will replace the value. This will make sure that the bottom most element for that horizontal distance is present in the map and if you see the tree from beneath that you will see that element. */