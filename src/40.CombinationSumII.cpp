#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tempRes;
    solve(res, 0, target, tempRes, candidates);
    return res;
  }

 private:
  void solve(vector<vector<int>>& res, const int pos, const int target,
             vector<int>& local, const vector<int>& num) {
    if (target == 0) {
      res.push_back(local);
      return;
    } else {
      for (int i = pos; i < num.size(); i++) {
        if (num[i] > target) return;
        if (i != 0 && num[i] == num[i - 1] && i > pos) continue;
        local.push_back(num[i]);
        solve(res, i + 1, target - num[i], local, num);
        local.pop_back();
      }
    }
  }
};