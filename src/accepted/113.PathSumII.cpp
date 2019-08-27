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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    vector<int> cur;
    solve(res, cur, root, sum);
    return res;
  }

 private:
  void solve(vector<vector<int>> &res, vector<int> &current, TreeNode *root,int sum) {
    if (!root) return;
    current.push_back(root->val);
    if (root->val == sum && !root->left && !root->right) {
      res.push_back(current);
    } else {
      solve(res, current, root->left, sum - root->val);
      solve(res, current, root->right, sum - root->val);
    }
    current.pop_back();
  }
};