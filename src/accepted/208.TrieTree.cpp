
#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
  string val;
  bool include;
  vector<Node *> children;

  Node(string x) : val(x), include(false), children(vector<Node *>()){};
} Node;

class Trie {
 private:
  Node *root;

  void doInsert(string &word, Node *parent, int depth) {
    if (depth == word.size()) {
      parent->include = true;
      return;
    }
    bool find = false;
    Node *target;
    vector<Node *> &children = parent->children;
    for (auto subNode : children) {
      if (subNode->val[depth] == word[depth]) {
        target = subNode;
        find = true;
        break;
      }
    }
    //如果遍历当前节点的所有subNode,均不包含的话，就创建一个
    if (!find) {
      target = new Node(word.substr(0, depth + 1));
      children.push_back(target);
    }
    doInsert(word, target, depth + 1);
  }

  bool doSearch(string &word, Node *parent, int depth) {
    if (depth == word.size() && parent->include) return true;
    vector<Node *> &children = parent->children;
    for (auto subNode : children) {
      if (subNode->val[depth] == word[depth]) {
        if (doSearch(word, subNode, depth + 1)) return true;
      }
    }
    return false;
  }

  bool doStartWith(string &word, Node *parent, int depth) {
    if (depth == word.size()) return true;
    vector<Node *> &children = parent->children;
    for (auto subNode : children) {
      if (subNode->val[depth] == word[depth]) {
        if (doStartWith(word, subNode, depth + 1)) return true;
      }
    }
    return false;
  }

 public:
  Trie() { root = new Node(""); }

  void insert(string word) { doInsert(word, root, 0); }

  bool search(string word) { return doSearch(word, root, 0); }

  bool startsWith(string prefix) { return doStartWith(prefix, root, 0); }
};
