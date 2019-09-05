#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
 public:
  int val;
  vector<Node *> neighbors;

  Node() {}

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
class Solution {
  unordered_map<Node *, Node *> map;

 public:
  Node *cloneGraph(Node *node) {
    if (!node) return NULL;
    Node *res = new Node();
    map[node] = res;
    dfs(node, res);
    return res;
  }

  void dfs(Node *origin, Node *res) {
    if (!origin) return;
    res->val = origin->val;
    vector<Node *> &children = origin->neighbors;
    if (!children.size()) return;
    vector<Node *> resChildren;
    for (auto i : children) {
      if (map.count(i)) {
        resChildren.push_back(map[i]);
        continue;
      }
      Node *t = new Node();
      map[i] = t;
      dfs(i, t);
      resChildren.push_back(t);
    }
    res->neighbors = resChildren;
  }
};

//优化了一下代码
class Solution {
  unordered_map<Node *, Node *> ref;

 public:
  Node *cloneGraph(Node *node) {
    if (ref.count(node)) return ref[node];
    ref[node] = new Node(node->val, vector<Node *>());
    for (auto i : node->neighbors) {
      ref[node]->neighbors.push_back(cloneGraph(i));
    }
    return ref[node];
  }
};