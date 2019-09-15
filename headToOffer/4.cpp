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
  TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    TreeNode *res = solve(pre, 0, vin, 0, vin.size() - 1);
    return res;
  }

 private:
  TreeNode *solve(vector<int> &pre, int pos, vector<int> &mid, int l, int r) {
    if (l > r) return NULL;
    if (l == r) return new TreeNode(mid[l]);
    int i = 0;
    while (mid[i] != pre[pos] && i <= r) i++;
    TreeNode *res = new TreeNode(mid[i]);
    res->left = solve(pre, pos + 1, mid, l, i - 1);
    res->right = solve(pre, pos + i - l + 1, mid, i + 1, r);
    return res;
  }
};
