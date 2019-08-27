#include <iostream>
#include <vector>
using namespace std;
//神仙解法
class Solution {
 public:
  vector<int> grayCode(int n) {
    int len = 1 << n;
    vector<int> res;
    for (int i = 0; i < len; i++) res.push_back(i ^ (i / 2));
    return res;
  }
};

//DP解法
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> res = {0};
    for (int i = 0; i < n; i++) {
      int len = res.size();
      for (int j = len - 1; j >= 0; j--) {
        res.push_back(res[j] | i << i);
      }
    }
    return res;
  }
};