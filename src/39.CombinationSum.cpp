#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> cur;
    sort(candidates.begin(), candidates.end());
    doCombinationSum(candidates, target, cur, res, 0);
    return res;
  }

 private:
  void doCombinationSum(vector<int>& candidates, int target,
                        vector<int>& current, vector<vector<int>>& res,
                        int from) {
    for (int i = from; i < candidates.size(); i++) {
      if (i > 0 && candidates[i] == candidates[i - 1]) continue;
      if (candidates[i] < target) {
        vector<int> copy = current;
        copy.push_back(candidates[i]);
        doCombinationSum(candidates, target - candidates[i], copy, res, i);
      } else if (candidates[i] == target) {
        vector<int> copy = current;
        copy.push_back(candidates[i]);
        res.push_back(copy);
        return;
      }
    }
  }
};

int main() {
  Solution sol;
  vector<int> candidates = {2, 3, 6, 7};
  vector<vector<int>> res = sol.combinationSum(candidates, 7);
  return 0;
}