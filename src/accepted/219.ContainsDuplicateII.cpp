#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if (!nums.size()) return false;
    unordered_map<int, int> ref;
    for (int i = 0; i < nums.size(); i++) {
      if (!ref.count(nums[i])) {
        ref.insert(nums[i], i);
        continue;
      }
      int pre = ref[nums[i]];
      if (i - pre > k) return true;
    }
    return false;
  }
};