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
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> ref;
    vector<int> res;
    TreeNode *temp = NULL;
    ref.push(root);
    // temp为空，stack也为空，就退出
    while (temp || !ref.empty()) {
      //如果temp是空的话,就从stack里面拿
      if (!temp) {
        temp = ref.top();
        ref.pop();
      }
      res.push_back(temp->val);
      temp = temp->left;
      if (temp->right) ref.push(temp->right);
    }
  return res;
  }
};