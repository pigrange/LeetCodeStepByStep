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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return genSubTree(preorder, inorder, 0, 0, preorder.size() - 1);
  }

 private:
  TreeNode* genSubTree(vector<int>& pre, vector<int>& in, int preIdx, int start,
                       int end) {
    if (start > end) return NULL;
    if (preIdx >= pre.size()) return NULL;
    int val = pre[preIdx];
    TreeNode* root = new TreeNode(val);
    if(start == end) return root;  
    int i = start;
    while (i < end) {
      if (in[i] == val) break;
      i++;
    }
    root->left = genSubTree(pre, in, preIdx + 1, start, i - 1);
    root->right = genSubTree(pre, in, preIdx + i - start + 1, i + 1, end);
    return root;
  }
};

int main() {
  Solution sol;
  vector<int> pre = {3, 9, 20, 15, 7};
  vector<int> in = {9, 3, 15, 20, 7};
  sol.buildTree(pre, in);
  return 0;
}