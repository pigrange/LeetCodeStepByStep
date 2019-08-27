#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int mySqrt(int x) {
    if (!x) return x;
    int base = 1;
    long temp;
    while ((temp = base * base) < x) base *= 2;
    if (temp == x) return base;
    int l = base / 2, r = base;
    while (l < r - 1) {
      int mid = l + (r - l) / 2;
      int t = mid * mid;
      if (t == x) return mid;
      if (t > x)
        r = mid;
      else
        l = mid;
    }
    return l;
  }
};
int main() {
  Solution sol;
  for (int i = 0; i < INT32_MAX; i++) {
    if ((int)sqrt(i) != sol.mySqrt(i)) cout << i << " is uncorrect! " << endl;
  }
  return 0;
}