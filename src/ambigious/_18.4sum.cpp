#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 3; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
      if (nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target)
        continue;
      for (int j = i + 1; j < len - 2; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        if (nums[i] + nums[j + 1] + nums[j + 2] + nums[j + 3] > target) break;
        if (nums[i] + nums[j] + nums[len - 1] + nums[len - 2] < target)
          continue;
        int t1 = nums[i], t2 = nums[j];
        int l = j + 1, r = len - 1;
        while (l < r) {
          if (nums[l] + nums[r] > target - t1 - t2) {
            r--;
          } else if (nums[l] + nums[r] < target - t1 - t2)
            l++;
          else {
            vector<int> v;
            v.push_back(t1);
            v.push_back(t2);
            v.push_back(nums[l]);
            v.push_back(nums[r]);
            res.push_back(v);
            while (l < r && nums[l] == v[2]) l++;
            while (l < r && nums[r] == v[3]) r--;
          }
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  Solution sol;
  vector<vector<int>> res = sol.fourSum(nums, 0);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ,";
    }
    cout << endl;
  }
}