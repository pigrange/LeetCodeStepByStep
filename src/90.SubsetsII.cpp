#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;
    res.push_back(temp);
    solve(res, nums, temp, 0);
    return res;
  }

 private:
  void solve(vector<vector<int>> &res, vector<int> &nums, vector<int> &temp,
             int pos) {
    for (int i = pos; i < nums.size(); i++) {
      if (i > pos && nums[i] == nums[i - 1]) continue;
      temp.push_back(nums[i]);
      res.push_back(temp);
      solve(res, nums, temp, i + 1);
      temp.pop_back();
    }
  }
};