#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);
    int res1 = 0, res2 = 0;
    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];
    dp[2] = nums[1];
    for (int i = 2; i < nums.size() - 1; i++) {
      dp[i + 1] = nums[i] + max(dp[i - 1], dp[i - 2]);
    }
    res1 = max(dp[nums.size() - 1], dp[nums.size() - 2]);
    dp[1] = 0;
    dp[3] = nums[2];
    for (int i = 3; i < nums.size(); i++) {
      dp[i + 1] = nums[i] + max(dp[i - 1], dp[i - 2]);
    }
    res2 = max(dp[nums.size()], dp[nums.size() - 1]);
    return max(res1, res2);
  }
};