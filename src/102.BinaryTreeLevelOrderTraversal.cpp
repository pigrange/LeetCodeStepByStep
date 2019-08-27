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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> q1, q2;
    if(!root) return res;   
    q1.push(root);
    while (!q1.empty() || !q2.empty()) {
      vector<int> temp = {};
      while (!q1.empty()) {
        TreeNode *head = q1.front();
        q1.pop();
        temp.push_back(head->val);
        if (head->left) q2.push(head->left);
        if (head->right) q2.push(head->right);
      }
      if (temp.size() > 0) res.push_back(temp);
      temp = {};
      while (!q2.empty()) {
        TreeNode *head = q2.front();
        q2.pop();
        temp.push_back(head->val);
        if (head->left) q1.push(head->left);
        if (head->right) q1.push(head->right);
      }
      if (temp.size() > 0) res.push_back(temp);
    }
    return res;
  }
};