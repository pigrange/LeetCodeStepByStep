#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int res = nums[0], small = res;
    for (int i = 1; i < nums.size(); i++) {
      int t = nums[i], p = t;
      p = max(p, p * nums[i - 1]);
      nums[i] = max(p, nums[i] * small);
      t = min(t, t * nums[i - 1]);
      small = min(t, t * small);
      res = max(res, nums[i]);
    }
    return res;
  }
};

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int big = nums[0], small = nums[0], res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      int newbig = big, newsmall = small;
      newbig = max(nums[i], big * nums[i]);
      newbig = max(newbig, small * nums[i]);
      newsmall = min(nums[i], big * nums[i]);
      newsmall = min(newsmall, small * nums[i]);
      big = newbig;
      small = newsmall;
      res = max(res, big);
    }
    return res;
  }
};