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
    int heightOfBinaryTree(TreeNode* root) {
        if(root == NULL){
          return 0;
        }
        int left = heightOfBinaryTree(root->left); 
        int right = heightOfBinaryTree(root->right); 
        
        return 1 + max(left, right); 

    }
};