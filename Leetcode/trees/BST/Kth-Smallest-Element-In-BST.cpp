// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int K;
  int ans;
  void solve(TreeNode *root) {
    if (root) {
      if (root->left) solve(root->left);
      if (K == 1) {
        ans = root->val;
        K--;
        return;
      } else {
        K--;
      }
      if (root->right) solve(root->right);
    }
  }
  int kthSmallest(TreeNode *root, int k) {
    K = k;
    solve(root);
    return ans;
  }
};