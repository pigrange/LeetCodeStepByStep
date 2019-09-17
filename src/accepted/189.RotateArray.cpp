#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int q = nums.size() - k % nums.size();
    reverse(nums.begin(), nums.begin() + q);
    reverse(nums.begin() + q, nums.end());
    reverse(nums.begin(), nums.end());
  }
};