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
  bool isBalanced(TreeNode *root) { return isSubBanlanced(root) != -1; }

 private:
  int isSubBanlanced(TreeNode *root) {
    if (!root) return 0;
    int l = isSubBanlanced(root->left);
    int r = isSubBanlanced(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1) return -1;
    return max(l, r) + 1;
  }
};