#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size(), farest = 0;
    for (int i = 0; i < n; i++) {
      if (farest < i) return false;
      farest = max(i + nums[i], farest);
    }
    return true;
  }
};

int main() {
  vector<int> nums = {2, 5, 0, 0};
  Solution sol;
  int res = sol.canJump(nums);
  cout << " res is " << res << endl;
  return 0;
}