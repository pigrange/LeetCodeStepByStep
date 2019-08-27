#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int start = 0, count = 1;
    while (start + nums[start] < nums.size() - 1) {
      int jump = nums[start];
      int i = 1, maxJump = jump, jumpPos = start + jump;
      cout << " start is " << start << " jump is " << jump << endl;
      while (i <= jump) {
        if (nums[start + i] + i > maxJump) {
          maxJump = nums[start + i] + i;
          jumpPos = start + i;
        }
        i++;
      }
      start = jumpPos;
      cout << "jump pos is " << jumpPos << endl;
      cout << " ---------------------- " << endl;
      count++;
    }
    return count;
  }
};

int main() {
  //   vector<int> nums = {2, 3, 1, 1, 4, 1, 3, 4, 1, 2, 5, 6, 5, 3, 4, 2, 4};
  vector<int> nums = {2, 3, 1, 1, 4, 1};
  Solution sol;
  int res = sol.jump(nums);
  cout << "res is " << res << endl;
  return 0;
}