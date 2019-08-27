#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (divisor == INT32_MIN) return (dividend == INT32_MIN);
    if (dividend == INT32_MIN && divisor == 1) return INT32_MIN;
    if (dividend == INT32_MIN && divisor == -2) return 1073741824;
    if (dividend == INT32_MIN && divisor == 2) return -1073741824;
    if (dividend == INT32_MIN) dividend = INT32_MIN + 1;
    int flag = ((dividend < 0) == (divisor < 0)) ? 1 : -1;
    return DFS(abs(dividend), abs(divisor)) * flag;
  }

 private:
  int DFS(int dividend, int divisor) {
    if (abs(dividend) < abs(divisor)) return 0;
    if (dividend == divisor) return 1;
    int base = 0, temp = 0;
    long accu = divisor;
    while (dividend > accu) {
      temp = accu;
      accu = (accu << 1) + divisor;
      base = (base << 1) + 1;
    }
    return base + DFS(dividend - temp, divisor);
  }
};

//转换为long做
class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT32_MIN && divisor == -1) return INT32_MAX;
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
    while (dvd >= dvs) {
      long temp = dvs, m = 1;
      while (temp << 1 <= dvd) {
        temp <<= 1;
        m <<= 1;
      }
      dvd -= temp;
      ans += m;
    }
    return sign * ans;
  }
};