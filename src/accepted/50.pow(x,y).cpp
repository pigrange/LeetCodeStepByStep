#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    int flag = 0;
    long m = n < 0 ? -(long)n : n;
    double res = 1;
    while (m > 0) {
      if (m % 2 == 1) res *= x;
      x = x * x;
      m /= 2;
    }
    if (n < 0) res = 1 / res;
    return res;
  }
};