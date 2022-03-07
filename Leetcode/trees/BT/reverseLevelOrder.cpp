// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

// not a good solution
class Solution
{
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    vector<vector<int>> result;
    TreeNode *temp;
    if (!root)
      return result;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      vector<int> curr;
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        temp = q.front();
        q.pop();
        curr.push_back(temp->val);
        if (temp->left)
        {
          q.push(temp->left);
        }
        if (temp->right)
        {
          q.push(temp->right);
        }
      }
      result.push_back(curr);
    }
    reverse(result.begin(),result.end());
    return result;
  }
};

class Solution2
{
public:
  vector<vector<int>> res;

  void DFS(TreeNode *root, int level)
  {
    if (root == NULL)
      return;
    if (level == res.size()) // The level does not exist in output
    {
      res.push_back(vector<int>()); // Create a new level
    }

    res[level].push_back(root->val); // Add the current value to its level
    DFS(root->left, level + 1);      // Go to the next level
    DFS(root->right, level + 1);
  }

  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    DFS(root, 0);
    return vector<vector<int>>(res.rbegin(), res.rend());
  }
};