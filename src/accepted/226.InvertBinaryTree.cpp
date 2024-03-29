#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
  }
};