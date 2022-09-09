// https://leetcode.com/problems/clone-graph/

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// asu code
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    unordered_map<int, Node*> map;
    queue<Node*> q;  // old node
    Node* start = new Node(node->val);
    map.insert({node->val, start});
    q.push(node);
    while (!q.empty()) {
      Node* old = q.front();
      q.pop();
      Node* copy = map[old->val];
      for (int i = 0; i < old->neighbors.size(); i++) {
        Node* newNode;
        if (map.find(old->neighbors[i]->val) == map.end()) {
          newNode = new Node(old->neighbors[i]->val);
          map.insert({old->neighbors[i]->val, newNode});
          q.push(old->neighbors[i]);
        } else {
          newNode = map[old->neighbors[i]->val];
        }
        copy->neighbors.push_back(newNode);
      }
    }
    return start;
  }
};

// shreyu code
class Solution {
 public:
  unordered_map<int, Node*> visited;
  Node* cloneGraph(Node* node) {
    if (!node) {
      return node;
    }
    if (visited.find(node->val) == visited.end()) {
      Node* newNode = new Node(node->val);
      visited.insert({newNode->val, newNode});
      for (int i = 0; i < node->neighbors.size(); i++) {
        newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
      }
      return newNode;
    } else {
      return visited.find(node->val)->second;
    }
  }
};