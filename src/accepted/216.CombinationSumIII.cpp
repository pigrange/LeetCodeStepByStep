#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> temp;
    dfs(res, temp, 0, n, 0, k);
    return res;
  }

 private:
  void dfs(vector<vector<int>>& res, vector<int>& temp, int depth, int need,
           int cur, int k) {
    if (depth == k + 1) {
      if (need == 0) res.push_back(temp);
      return;
    }
    if (depth > k) return;
    for (int i = cur; i <= need && i <= 9; i++) {
      temp.push_back(i);
      dfs(res, temp, depth + 1, need - i, i + 1, k);
      temp.pop_back();
    }
  }
};

void dfs(int k, int n, int start, vector<int> vec, vector<vector<int>>& res) {
  if (k == 0 && n == 0) {
    res.push_back(vec);
  }
  if (k < 0 || n < 0) return;
  for (int i = start; i <= 9; i++) {
    vec.push_back(i);
    dfs(k - 1, n - i, i + 1, vec, res);
    vec.erase(vec.end() - 1);
  }
}
vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> res;
  vector<int> vec;
  dfs(k, n, 1, vec, res);
  return res;
}