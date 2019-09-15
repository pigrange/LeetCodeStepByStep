#include <math.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    if (arr.empty()) return 0;
    int count = 0;
    int m = (int)pow(10, 9) + 7;
    long max_sum = 0, sum = 0, total_sum = 0;
    bool flag = true;
    for (int i = 0; count < 2;) {
      if (arr[i] < 0) flag = false;
      total_sum = (total_sum + arr[i]) % m;
      sum = max((long)arr[i], (sum + arr[i]) % m);
      max_sum = max(max_sum, sum);
      i++;
      if (i == arr.size()) {
        count++;
        i = 0;
      }
    }
    //全部为正数
    if (flag) {
      int base = max_sum / 2;
      max_sum = 0;
      for (int i = 0; i < k; i++) {
        max_sum = (max_sum + base) % m;
      }
    } else if (total_sum > 0) {
      int t = total_sum;
      for (int i = 1; i < k - 2; i++) {
        t += total_sum;
      }
      max_sum = (max_sum + total_sum) % m;
    }
    return max_sum;
  }
};