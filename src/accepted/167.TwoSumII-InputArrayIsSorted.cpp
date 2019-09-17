#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int end = nums.size() - 1;
    for (int i = 0; i <= end; i++) {
      if (nums[i] + nums[end] < target) continue;
      if (nums[i] + nums[end] == target) return {i, end};
      int l = i + 1, r = end - 1, tar = target - nums[i];
      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == tar) return {i, mid};
        if (nums[mid] > tar) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
    }
    return {0, 0};
  }
};
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    vector<int> res;
    while (left < right) {
      long long val = numbers[left] + numbers[right];
      if (val == target) {
        res.push_back(left + 1);
        res.push_back(right + 1);
        break;
      } else if (val < target)
        left++;
      else
        right--;
    }
    return res;
  }
};
