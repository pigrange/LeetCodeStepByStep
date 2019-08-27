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
  void flatten(TreeNode *root) { genSubLink(root); }

 private:
  TreeNode *genSubLink(TreeNode *root) {
    if (!root) return NULL;
    TreeNode *leftEnd = genSubLink(root->left);
    TreeNode *rightEnd = genSubLink(root->right);
    if (!leftEnd) {
      if (!rightEnd) return root;
      return rightEnd;
    }
    if (!rightEnd) {
      root->right = root->left;
      root->left = NULL;
      return leftEnd;
    }
    leftEnd->right = root->right;
    root->right = root->left;
    root->left = NULL;
    return rightEnd;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(2);
  root->left = left;
  Solution sol;
  sol.flatten(root);
  while (root) {
    cout << root->val << " ";
    root = root->right;
  }
  return 0;
}