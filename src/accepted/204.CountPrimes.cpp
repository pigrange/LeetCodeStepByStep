#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) return 0;
    int res = 0;
    vector<bool> ref(n + 1, false);
    for (int i = 2; i < n; i++) {
      if (ref[i]) continue;
      res++;
      int k = n / i;
      for (int j = 2; j <= k; j++) {
        ref[j * i] = true;
      }
    }
    return res;
  }
};