#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int max_sum = INT32_MIN, sum = 0;
    for (int n : nums) {
      sum = max(n, sum + n);
      max_sum = max(max_sum, sum);
    }
    return max_sum;
  }
};