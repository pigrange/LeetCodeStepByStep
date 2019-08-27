#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, red;
    while (l < r) {
      while (nums[l] != 2) {
        if (nums[l] == 1) swap(nums[l], nums[red++]);
        l++;
      }
      swap(nums[r], nums[l]);
      while (nums[r] != 0) {
        if (nums[r] == 1) swap(nums[r], nums[red++]);
        r--;
      }
    }
  }
};

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    for (int i = 0; i < r; i++) {
      while (nums[i] == 2 && i < r) swap(nums[i], nums[r--]);
      while (nums[i] == 0 && i > l) swap(nums[i], nums[l++]);
    }
  }
};