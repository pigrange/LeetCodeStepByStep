#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    unordered_map<int, int> ref;
    vector<int> temp;
    vector<vector<int>> res;
    solve(nums, temp, ref, res, 1);
    return res;
  }

 private:
  void solve(vector<int> &nums, vector<int> &temp, unordered_map<int, int> &ref,
             vector<vector<int>> &res, int depth) {
    if (depth == nums.size() + 1) {
      res.push_back(temp);
      return;
    }
    for (int num : nums) {
      if (ref[num] == 1) continue;
      ref[num] = 1;
      vector<int> current = temp;
      current.push_back(num);
      solve(nums, current, ref, res, depth + 1);
      ref[num] = 0;
    }
  }
};

class Solution {
 public:
  vector<vector<int>> permute(vector<int> &num) {
    vector<vector<int>> result;
    permuteRecursive(num, 0, result);
    return result;
  }

  void permuteRecursive(vector<int> &num, int begin,
                        vector<vector<int>> &result) {
    if (begin >= num.size()) {
      result.push_back(num);
      return;
    }

    for (int i = begin; i < num.size(); i++) {
      if (i > 0 && num[i] == num[i - 1]) continue;
      swap(num[begin], num[i]);
      permuteRecursive(num, begin + 1, result);
      swap(num[begin], num[i]);
    }
  }
};
