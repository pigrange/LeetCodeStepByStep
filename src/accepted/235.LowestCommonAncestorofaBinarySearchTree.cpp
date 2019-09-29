#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
      int val = root->val;
      int big = p->val > q->val ? p->val : q->val;
      int small = p->val + q->val - big;
      if (small <= val && big >= val) return root;
      if (big < val) root = root->left;
      if (small > val) root = root->right;
    }
  }
};