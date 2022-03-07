//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/?ref=lbp
//Morris Traversal

//https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inorder(root -> left, nodes);
        nodes.push_back(root -> val);
        inorder(root -> right, nodes);
    }
};
