#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &num) {
    vector<vector<int>> result;
    sort(num.begin(), num.end());
    permuteRecursive(num, 0, result);
    return result;
  }

  void permuteRecursive(vector<int> num, int begin,
                        vector<vector<int>> &result) {
    if (begin >= num.size()) {
      result.push_back(num);
      return;
    }

    for (int i = begin; i < num.size(); i++) {
      if (i > begin && num[i] == num[begin]) continue;
      swap(num[begin], num[i]);
      permuteRecursive(num, begin + 1, result);
    }
  }
};

class Solution {
 public:
  vector<vector<int>> res;

  void permuteRec(vector<int> nums, int pos) {
    int n = nums.size();
    if (pos == n) {
      res.push_back(nums);
      return;
    }
    for (int i = pos; i < n; ++i) {
      if (i != pos && nums[i] == nums[pos]) continue;
      swap(nums[pos], nums[i]);
      permuteRec(nums, pos + 1);
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    permuteRec(nums, 0);
    return res;
  }
};