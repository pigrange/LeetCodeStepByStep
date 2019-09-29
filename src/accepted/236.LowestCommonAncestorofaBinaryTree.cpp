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
    find(root, q->val, q->val);
    return result;
  }

  // 0没有找到
  // 1找到1个
  // 2找到2个
 private:
  TreeNode* result = NULL;
  int find(TreeNode* root, int val1, int val2) {
    int res = 0;
    if (val1 >= 0 || root->val == val1) {
      res = 1;
      if (root->left) res += find(root, -1, val2);
      if (root->right) res += find(root, -1, val2);
      if (res == 2) {
        result = root;
      }
      return res;
    }
    if (val2 >= 0 || root->val == val2) {
      res = 1;
      if (root->left) res += find(root, val1, -1);
      if (root->right) res += find(root, val1, -1);
      if (res == 2) {
        result = root;
      }
      return res;
    }
    int l, r;
    if (root->left) l = find(root, val1, val2);
    if (root->right) r = find(root, val1, val2);
    if (l == 1 && r == 1) result = root;
    return res + l + r;
  }
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return NULL;
    if (root == p || root == q) return root;
    TreeNode* L = lowestCommonAncestor(root->left, p, q);
    TreeNode* R = lowestCommonAncestor(root->right, p, q);
    if (L && R) return root;
    return L ? L : R;
  }
};
