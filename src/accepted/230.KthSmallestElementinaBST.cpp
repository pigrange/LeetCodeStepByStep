#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    solve(root, k);
    return res;
  }

 private:
  int res = 0;
  int solve(TreeNode *root, int k) {
    if (root->left) k = kthSmallest(root->left, k);
    if (k == 0) return 0;
    if (--k == 0) {
      res = root->val;
      return k;
    }
    if (root->right) k = kthSmallest(root->right, k);
    return k;
  }
};

class Solution {
 public:
  int kthSmallest(TreeNode *root, int k) {
    vector<TreeNode *> stack;
    while (true) {
      while (root) {
        stack.push_back(root);
        root = root->left;
      }
      root = *--stack.end();
      if (--k == 0) return root->val;
      root = root->right;
    }
  }
};