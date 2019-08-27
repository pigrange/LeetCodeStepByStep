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
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    return getDepth(root);
  }

 private:
  int getDepth(TreeNode *root) {
    int l = root->left ? getDepth(root->left) : 0;
    int r = root->right ? getDepth(root->right) : 0;
    return max(l, r) + 1;
  }
};