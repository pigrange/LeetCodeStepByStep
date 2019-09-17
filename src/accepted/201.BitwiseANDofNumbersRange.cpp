#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int i = 0;
    while (m != n) {
      m >>= 1;
      n >>= 1;
      i++;
    }
    return m << i;
  }
};
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    if (m == n) return m;
    return rangeBitwiseAnd(m >> 1, n >> 1) << 1;
  }
};