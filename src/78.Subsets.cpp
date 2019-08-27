#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    res.push_back(temp);
    solve(res, temp, nums, 0);
    return res;
  }

 private:
  void solve(vector<vector<int>>& res, vector<int>& temp, vector<int>& nums,int start) {
    for (int i = start; i < nums.size(); i++) {
      temp.push_back(nums[i]);
      res.push_back(temp);
      solve(res, temp, nums, i + 1);
      temp.pop_back();
    }
  }
};