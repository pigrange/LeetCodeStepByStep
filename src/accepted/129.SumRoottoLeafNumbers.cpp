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
  int sumNumbers(TreeNode *root) {
    if (!root) return 0;
    return dfs(root, 0);
  }

 private:
  int dfs(TreeNode *root, int acc) {
    int tempSum = acc * 10 + root->val;
    if (!root->left && !root->right) return tempSum;
    int l = root->left ? dfs(root->left, tempSum) : 0;
    int r = root->right ? dfs(root->right, tempSum) : 0;
    cout << "l : " << l << "r : " << r << endl;
    return l + r;
  }
};