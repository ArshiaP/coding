// https://leetcode.com/problems/validate-binary-search-tree/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  void inTrav(TreeNode *node, bool *ans, long int *prevVal)
  {
    if (node)
    {
      inTrav(node->left, ans, prevVal);
      if (*prevVal >= node->val)
      {
        *ans = false;
        return;
      }
      else
      {
        *prevVal = node->val;
      }
      inTrav(node->right, ans, prevVal);
    }
  }

  bool isValidBST(TreeNode *root)
  {
    bool ans = true;
    long int prevVal = LONG_MIN;
    inTrav(root, &ans, &prevVal);
    return ans;
  }
};