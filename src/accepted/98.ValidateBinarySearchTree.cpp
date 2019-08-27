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
  int pre = INT32_MIN;

 public:
  bool isValidBST(TreeNode *root) {
    if (!root) return true;
    return solve(root);
  }

 private:
  bool solve(TreeNode *root) {
    bool flag;
    flag = root->left ? solve(root->left) : true;
    flag = flag && (root->val > pre);
    if (!flag) return false;
    pre = root->val;
    return root->right ? solve(root->right) : true;
  }
};