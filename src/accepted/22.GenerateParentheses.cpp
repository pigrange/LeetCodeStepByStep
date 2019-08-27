#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    DFS(n - 1, n, "(", res);
    return res;
  }

 private:
  void DFS(int left, int right, string pre, vector<string>& res) {
    if (left == 0 && right == 0) {
      res.push_back(pre);
      return;
    }
    if (left > 0 && left <= right) DFS(left - 1, right, pre + "(", res);
    if (right > 0 && left <= right) DFS(left, right - 1, pre + ")", res);
  }
};