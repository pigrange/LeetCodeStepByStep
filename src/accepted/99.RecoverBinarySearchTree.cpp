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
  TreeNode *firstNode = NULL, *secondNode, *pre = NULL;

 public:
  void recoverTree(TreeNode *root) {
    trasersal(root);
    swap(firstNode->val, secondNode->val);
  }

 private:
  void trasersal(TreeNode *root) {
    if (!root) return;
    trasersal(root->left);
    if (pre) {
      //出现了下降
      if (root->val <= pre->val) {
        if (!firstNode) firstNode = pre;
        if (firstNode) secondNode = root;
      }
    }
    pre = root;
    trasersal(root->right);
  }
};