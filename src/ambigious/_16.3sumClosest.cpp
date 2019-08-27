#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < nums.size(); i++) {
      int l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int temp = nums[l] + nums[r] + nums[i];
        if (abs(temp - target) < abs(res - target)) {
          res = temp;
        }
        if (temp > target) {
          r--;
        } else if (temp < target) {
          l++;
        } else {
          return target;
        }
      }
    }
    return res;
  }
};