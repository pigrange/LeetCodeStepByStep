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
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0) return vector<TreeNode *>();
    return genTrees(1, n);
  }

 private:
  vector<TreeNode *> genTrees(int start, int end) {
    vector<TreeNode *> res;
    if (start > end) {
      res.push_back(NULL);
      return res;
    } else if (start == end) {
      res.push_back(new TreeNode(start));
      return res;
    }
    vector<TreeNode *> left, right;
    for (int i = start; i <= end; i++) {
      left = genTrees(start, i - 1);
      right = genTrees(i + 1, end);
      for (auto lnode : left) {
        for (auto rnode : right) {
          TreeNode *root = new TreeNode(i);
          root->left = lnode;
          root->right = rnode;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};

class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) { return getSubTree(1, n); }

 private:
  vector<TreeNode *> getSubTree(int start, int end) {
    if (start > end) return {new TreeNode(NULL)};
    if (start == end) return {new TreeNode(start)};
    vector<TreeNode *> res;
    for (int i = start; i <= end; i++) {
      //生成左子树
      vector<TreeNode *> left = getSubTree(1, i - 1);
      //生成右子树
      vector<TreeNode *> right = getSubTree(i + 1, end);
      for (auto l : left) {
        for (auto r : right) {
          TreeNode *root = new TreeNode(i);
          root->left = l;
          root->right = r;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};