#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    int l = 1, r = nums.size() - 1, count = 1;
    while (l <= r) {
      if (nums[l] == nums[l - 1]) {
        ++count;
        if (count > 2) {
          int p = l;
          while (p < nums.size() && nums[p] == nums[l]) p++;
          reverse(nums.begin() + p, nums.begin() + r + 1);
          reverse(nums.begin() + l, nums.begin() + r + 1);
          r = r - (p - l);
          continue;
        }
      } else {
        count = 1;
      }
      l++;
    }
    return l;
  }
};

//神仙解法
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
      if (nums[i] == nums[i - 2 - count])
        count++;
      else
        nums[i - count] = nums[i];
    return n - count;
  }
};

//无解了
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
      if (i < 2 || n > nums[i - 2]) nums[i++] = n;
    return i;
  }
};

int main() {
  vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
  //   vector<int> nums = {1, 1, 1, 1, 4, 4, 4, 4};
  Solution sol;
  int res = sol.removeDuplicates(nums);
  cout << "res is " << res << endl;
  for (int i = 0; i < res; i++) cout << nums[i] << " ";
  return 0;
}