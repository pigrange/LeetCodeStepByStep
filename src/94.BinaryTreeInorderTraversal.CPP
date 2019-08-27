#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

//二叉树的中序遍历
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root) solve(root, res);
    return res;
  }

 private:
  void solve(TreeNode *root, vector<int> &res) {
    if (root->left != NULL) solve(root->left, res);
    res.push_back(root->val);
    if (root->right != NULL) solve(root->right, res);
  }
};

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> stack;
    vector<int> res;
    if (root) stack.push(root);
    while (stack.size() > 0) {
      TreeNode *top = stack.top();
      if (top->left != NULL) {
        stack.push(top->left);
        top->left = NULL;
      } else {
        res.push_back(top->val);
        stack.pop();
        if (top->right != NULL) stack.push(top->right);
      }
    }
    return res;
  }
};