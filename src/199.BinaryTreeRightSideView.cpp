#include <iostream>
#include <queue>
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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> q1, q2;
    q1.push(root);
    while (!(q1.empty() && q2.empty())) {
      bool seen = false;
      while (!q1.empty()) {
        TreeNode *head = q1.front();
        q1.pop();
        if (!seen) {
          res.push_back(head->val);
          seen = true;
        }
        if (head->right) q2.push(head->right);
        if (head->left) q2.push(head->left);
      }
      seen = false;
      while (!q2.empty()) {
        TreeNode *head = q2.front();
        q2.pop();
        if (!seen) {
          res.push_back(head->val);
          seen = true;
        }
        if (head->right) q1.push(head->right);
        if (head->left) q1.push(head->left);
      }
    }
    return res;
  }
};