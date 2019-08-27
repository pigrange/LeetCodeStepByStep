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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int end = postorder.size() - 1;
    return genSubTree(postorder, inorder, end, end, 0);
  }

 private:
  TreeNode* genSubTree(vector<int>& post, vector<int>& in, int index, int start, int end) {
    if (start < end) return NULL;
    if (index < 0) return NULL;
    int val = post[index];
    TreeNode* root = new TreeNode(val);
    if (start == end) return root;
    int i = start;
    while (i >= end) {
      if (in[i] == val) break;
      i--;
    }
    root->right = genSubTree(post, in, index - 1, start, i + 1);
    root->left = genSubTree(post, in, index + i - start - 1, i-1, end);
    return root;
  }
};