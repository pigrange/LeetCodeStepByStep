#include <algorithm>
#include <iostream>
#include <stack>
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
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode *> ref;
    ref.push(root);
    while (!ref.empty()) {
      TreeNode *top = ref.top();
      ref.pop();
      if (top->right) ref.push(top->right);
      if (top->left) ref.push(top->left);
      res.push_back(top->val);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};