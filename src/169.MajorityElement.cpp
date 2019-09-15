#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int count = 0, candidate = 0;
    for (auto num : nums) {
      if (!count) candidate = num;
      count += (num == candidate) ? 1 : -1;
    }
    return candidate;
  }
};