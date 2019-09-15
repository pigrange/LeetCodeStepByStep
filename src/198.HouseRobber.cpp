#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() < 3) return max(nums[0], nums[1]);
    vector<int> ref(nums.size() + 1, 0);
    ref[1] = nums[0];
    ref[2] = nums[1];
    for (int i = 2; i < nums.size(); i++) {
      ref[i + 1] = max(ref[i - 1], ref[i - 2]) + nums[i];
    }
    return ref[nums.size()];
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1};
  Solution sol;
  int res = sol.rob(nums);
  return 0;
}