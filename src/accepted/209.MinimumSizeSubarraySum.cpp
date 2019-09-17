#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (!nums.size()) return 0;
    int p1 = 0, p2 = 0, window = 0, res = INT32_MAX;
    while (p2 < nums.size()) {
      while (window < s && p2 < nums.size()) {
        window += nums[p2++];
      }
      while (window >= s && p1 < p2) {
        res = min(res, p2 - p1);
        window -= nums[p1++];
      }
    }
    return res == INT32_MAX ? 0 : res;
  }
};