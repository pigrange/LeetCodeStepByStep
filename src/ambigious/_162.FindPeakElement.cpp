#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] > nums[mid + 1]) {
        r = mid + 1;
      } else {
        l = mid;
      }
    }
    return nums[l];
  }
};