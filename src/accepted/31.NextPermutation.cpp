#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    if (len < 2) return;
    //找出第一个升序的位置
    int unsortPos = findUnsortPos(nums);
    if (unsortPos == len - 1) {
      sort(nums.begin(), nums.end());
      return;
    }

    //找出升序的次大值
    int targetPos = unsortPos + 1;
    for (int i = unsortPos + 1; i < len; i++) {
      if (nums[i] > nums[unsortPos] && nums[i] < nums[targetPos]) {
        targetPos = i;
      }
    }
    //交换次大值和升序开始位置的值
    swap(nums[targetPos], nums[unsortPos]);
    sort(nums.begin() + unsortPos + 1, nums.end());
  }

 private:
  int findUnsortPos(vector<int>& nums) {
    int i = 0;
    for (; i < nums.size() - 1; i++) {
      if (nums[i] < nums[i + 1]) break;
    }
    return i;
  }
};

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size(), k, l;
    for (k = n - 2; k >= 0; k--) {
      //反向找出第一个出现升序的位置
      if (nums[k] < nums[k + 1]) {
        break;
      }
    }
    if (k < 0) {
      //如果全部都是降序，则直接反转
      reverse(nums.begin(), nums.end());
    } else {
      //反向找出大于k的第一个元素  
      for (l = n - 1; l > k; l--) {
        if (nums[l] > nums[k]) {
          break;
        }
      }
      swap(nums[k], nums[l]);
      reverse(nums.begin() + k + 1, nums.end());
    }
  }
};