// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> result;
    if (!root)
      return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      vector<int> curr;
      int size = q.size();
      for (int i = 0; i < size; ++i)
      {
        TreeNode *node = q.front();
        q.pop();
        curr.push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
      result.push_back(curr);
    }
    return result;
  }
};