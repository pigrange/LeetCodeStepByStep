#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
  stack<TreeNode *> ref;

 public:
  BSTIterator(TreeNode *root) { ref.push(root); }

  /** @return the next smallest number */
  int next() {
    TreeNode *top = ref.top();
    while (top->left) {
      TreeNode *t = top->left;
      top->left = NULL;
      ref.push(t);
      top = t;
    }
    // pop第一个没有left的节点
    ref.pop();
    ref.push(top->right);
    return top->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !ref.empty(); }
};