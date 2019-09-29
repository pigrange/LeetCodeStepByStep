#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> ref1(len, 1);
    vector<int> ref2(len, 1);
    for (int i = 1; i < len; i++) {
      ref1[i] = nums[i - 1] * ref1[i - 1];
    }
    for (int j = len - 2; j >= 0; j--) {
        
      ref2[j] = nums[j + 1] * ref2[j + 1];
    }
    for (int i = 0; i < len; i++) ref1[i] *= ref2[i];
    return ref1;
  }
};
