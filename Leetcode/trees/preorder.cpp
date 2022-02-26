// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
  vector<int> preorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> s;
    vector<int> result;
    if (!root)
      return result;
    while (root || !s.empty())
    {
      if (root)
      {
        result.push_back(root->val);
        if (root->right)
        {
          s.push(root->right);
        }
        root = root->left;
      }
      else
      {
        root = s.top();
        s.pop();
      }
    }
    return result;
  }
};

class Solution2
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    stack<TreeNode *> nodeStack;
    vector<int> result;
    // base case
    if (root == NULL)
      return result;
    nodeStack.push(root);
    while (!nodeStack.empty())
    {
      TreeNode *node = nodeStack.top();
      result.push_back(node->val);
      nodeStack.pop();
      if (node->right)
        nodeStack.push(node->right);
      if (node->left)
        nodeStack.push(node->left);
    }
    return result;
  }
};

class Solution3
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> nodes;
    preorder(root, nodes);
    return nodes;
  }

private:
  void preorder(TreeNode *root, vector<int> &nodes)
  {
    if (!root)
    {
      return;
    }
    nodes.push_back(root->val);
    preorder(root->left, nodes);
    preorder(root->right, nodes);
  }
};

class Solution3
{
public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> ans;

    if (root == NULL)
    {
      return ans;
    }

    stack<TreeNode *> stck;
    TreeNode *current = root;

    while (!(current == NULL && stck.empty()))
    {
      while (current != NULL)
      {
        ans.push_back(current->val);
        stck.push(current);
        current = current->left;
      }

      current = stck.top();
      stck.pop();
      current = current->right;
    }
    return ans;
  }
};