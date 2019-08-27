#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] > nums[r]) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    int r1 = binSerach(nums, 0, l - 1, target);
    int r2 = binSerach(nums, l, nums.size() - 1, target);
    if (nums[r1] == target) return r1;
    if (nums[r2] == target) return r2;
    return -1;
  }

 private:
  int binSerach(vector<int>& nums, int l, int r, int target) {
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = int(nums.size()) - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      // nums[0]>target 即说明target在small区间
      // nums[0]>nums[mid] 即说明mid在small区间
      // target > nums[mid] 即说明 mid 在small区间并且比target小

      if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
        l = mid + 1;
      else
        r = mid;
    }
    return l == r && nums[l] == target ? l : -1;
  }
};

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int num = nums[mid];
      // nums[mid] 和target不在同义侧的时候
      if ((num < nums[0]) != (target < nums[0])) {
        num = target < nums[0] ? INT32_MIN : INT32_MAX;
      }
      if (num < target)
        l = mid + 1;
      else if (num > target)
        r = mid;
      else
        return mid;
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 2;
  Solution sol;
  int res = sol.search(nums, target);
  cout << res;
  return 0;
}