// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#
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
  if (str.length() == 0 || str[0] == 'N') return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;) ip.push_back(str);

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
    if (i >= ip.size()) break;
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
 private:
  Node *temp;

 public:
  /*Logic -
  1.If a node has both left and right child,calculate the sum of the path of left+node+right. calculate the left and right child's maximum. compare the three, the maximum is the answer.
  2.If the node is null, return int_min(if assigned 0 and the paths of the parent's other child node or parent is negative then the null node would be considered which we dont want)
  3.If a node has either left or right child, then we dont want to calculate it's path unless it is the root.

  4.When calculating the max depth of a node, take into consideration the following -
  i)If the root is null - return 0.
  ii)Check if it has both l and r child -- if yes, calculate max depth by root->data + max of maxdepthsum(l) and maxdepthsum(r)
  iii)If only one exists return root->data + maxdepthsum(existing child) -- this ensures that the null node isnt selected(if the return statement of the ii) point was used, then the maximum would be 0(null's value) instead of the existing child if the child's data was negative).*/

  int maxDepthSum(Node *root, int &ans) {
    if (root == NULL) {
      return 0;
    }
    if (!root->left and !root->right) {
      return root->data;
    }
    int l = maxDepthSum(root->left, ans);
    int r = maxDepthSum(root->right, ans);

    if (root->left and root->right or root == temp) {
      ans = max(ans, root->data + l + r);
      return root->data + max(l, r);
    }
    return root->left ? root->data + l : root->data + r;
  }

  int maxPathSum(Node *root) {
    temp = root;
    int ans = INT_MIN;
    maxDepthSum(root, ans);
    return ans;
  }
};

class Solution2 {
 private:
  Node *superRoot;
  int flag = 0;

 public:
  int maxDepthSum(Node *root) {
    if (!root) {
      return 0;
    }

    // if both sides do not exit don't go further
    if (!root->left and !root->right) {
      return root->data;
    }
    int l = maxDepthSum(root->left);
    int r = maxDepthSum(root->right);

    // go both sides only if both sides exist
    if (root->left and root->right) {
      return root->data + max(l, r);
    }

    // if any one side is there then only go to that side
    return root->left ? root->data + l : root->data + r;

    // we did all this so that when comparing a negative number on one side and a null(0) on another side we do not choose the 0. we simply don't go to null side.
  }

  int maxPathSum(Node *root) {
    // we need to store the original root for the if condition
    if (!flag) {
      flag = 1;
      superRoot = root;
    }
    // so that when we compare a negative number (which might be the answer) and a null(0), we don't choose the 0
    if (!root) {
      return INT_MIN;
    }

    // so that we don't consider a single leaf node as the answer
    if (!root->left and !root->right) {
      return INT_MIN;
    }

    int curr = INT_MIN;

    // consider the current root as an answer only if it has 2 leaf nodes or if it is the super root, so that the current node is not selected as one of the leaf nodes
    //--- for test case ---
    //         7
    //      /    \               
    //    Null   -3
    if (root->left and root->right or root == superRoot) {
      curr = root->data + maxDepthSum(root->left) + maxDepthSum(root->right);
    }

    int left = maxPathSum(root->left);
    int right = maxPathSum(root->right);

    return max(curr, max(left, right));
  }
};

int main() {
  int tc;
  scanf("%d ", &tc);
  while (tc--) {
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    Solution ob;
    cout << ob.maxPathSum(root) << "\n";
  }
  return 0;
}