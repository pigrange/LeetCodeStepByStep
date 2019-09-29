#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<string> res;
    int p1 = 0, p2 = 1, len = nums.size();
    while (p2 <= len) {
      if (p2 == len || (p2 < len && nums[p2] - nums[p2 - 1] > 1)) {
        string s = "", t = "";
        if (nums[p2 - 1] == nums[p1]) {
          s += toString(nums[p1]);
        } else {
          s += toString(nums[p1]);
          s += "->";
          s += toString(nums[p2 - 1]);
        }
        res.push_back(s);
        p1 = p2;
      }
      p2++;
    }
    return res;
  }

 private:
  string toString(int val) {
    if (val == 0) return "0";
    string res = "";
    bool neg = false;
    if (val < 0) {
      neg = true;
      val = -val;
    }
    while (val > 0) {
      res.push_back(val % 10 + '0');
      val = val / 10;
    }
    reverse(res.begin(), res.end());
    if (neg) res.push_back('-');
    return res;
  }
};