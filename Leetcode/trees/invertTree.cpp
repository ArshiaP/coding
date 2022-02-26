//https://leetcode.com/problems/invert-binary-tree/

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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
          TreeNode *left= invertTree(root->left);
          TreeNode *right = invertTree(root->right);

          TreeNode *temp = left;
          left = right;
          right = temp;
        }
        return root;
    }
};

//optimised
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
          TreeNode *temp= invertTree(root->left);
          root->left = invertTree(root->right);
          root->right = temp;
        }
        return root;
    }
};