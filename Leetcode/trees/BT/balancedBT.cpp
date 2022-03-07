// https://leetcode.com/problems/balanced-binary-tree/

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
  bool flag = true;
  int checkBalanced(TreeNode *root)
  {
    if (flag)
    {
      if (root == NULL)
      {
        return 0;
      }
      int lh = checkBalanced(root->left);
      int rh = checkBalanced(root->right);

      if (abs(lh - rh) > 1)
      {
        flag = false;
      }
      return 1 + max(lh, rh);
    }
    return 0;
  }
  bool isBalanced(TreeNode *root)
  {
    int i = checkBalanced(root);
    return flag;
  }
};