//https://leetcode.com/problems/diameter-of-binary-tree/

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

//diameter is max left height+ right height.
//need to calculate this value (left_height + right_height) for each node and update the result. 

class Solution {
public:

    int height(TreeNode *root,int& ans){
      if(root == NULL){
          return 0;
      }
      int lh = height(root->left,ans);
      int rh = height(root->right,ans);

      ans = max(ans,lh+rh);
      
      return 1+ max(lh,rh); //counts edges
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root,ans);
        return ans;
    }
};