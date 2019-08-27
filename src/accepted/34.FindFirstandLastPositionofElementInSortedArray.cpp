#include <iostream>
#include <vector>
using namespace std;
// 12ms
class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1, tarPos = -1;
    if (r == -1) return {-1, -1};
    vector<int> res;
    //进行二分查找寻找左边
    while (l < r) {
      int mid = (l + r - 1) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else if (r != mid) {
        r = mid;
      } else {
        break;
      }
    }
    res.push_back(l);
    //右边进行二分查找
    r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    res.push_back(l);
    return res;
  }
};

//稍微优化了一下,8ms;
class Solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    if (r == -1) return {-1, -1};
    vector<int> res;
    //进行二分查找寻找左边
    while (l < r) {
      int mid = (l + r - 1) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else if (r != mid) {
        r = mid;
      } else {
        break;
      }
    }
    if (l >= 0 && nums[l] == target) {
      res.push_back(l);
    } else {
      return {-1, -1};
    }
    //右边进行二分查找
    r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    res.push_back(l);
    return res;
  }
};