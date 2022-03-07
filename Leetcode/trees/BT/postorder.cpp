// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> s;
    vector<int> result;
    if (!root)
      return result;
    while (root || !s.empty())
    {
      while (root)
      {
        s.push(root);
        root = root->left;
      }
      auto t = s.top()->right;
      if (t)
      {
        root = t;
      }
      else
      {
        auto t = s.top();
        result.push_back(t->val);
        s.pop();
        while (!s.empty() and t == s.top()->right)
        {
          t = s.top();
          result.push_back(t->val);
          s.pop();
        }
      }
    }
  }
};

class Solution2
{
public:
  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> nodes;
    postorder(root, nodes);
    return nodes;
  }

private:
  void postorder(TreeNode *root, vector<int> &nodes)
  {
    if (!root)
    {
      return;
    }
    postorder(root->left, nodes);
    postorder(root->right, nodes);
    nodes.push_back(root->val);
  }
};



//two stacks
//https://www.geeksforgeeks.org/iterative-postorder-traversal/

class Solution3{
  public:
  void postOrderIterative(TreeNode* root)
{
    if (root == NULL)
        return;
 
    // Create two stacks
    stack<TreeNode*> s1, s2;
 
    // push root to first stack
    s1.push(root);
    TreeNode* node;
 
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
 
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
 
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->val << " ";
    }
}
};