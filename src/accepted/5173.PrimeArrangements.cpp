#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  long numPrimeArrangements(int n) {
    long long res = 1;
    int primeCount = 0;
    //从2到n进行寻找
    for (int m = 2; m <= n; m++) {
      //对每一个m进行计算
      bool flag = true;
      for (int i = 2; i <= int(sqrt(m)); ++i) {
        if (m % i == 0) {
          flag = false;
          continue;
        }
      }
      if (flag) {
        primeCount++;
      }
    }

    int left = n - primeCount;
    int mod = pow(10, 9) + 7;
    while (primeCount) {
      res = (res * primeCount) % mod;
      primeCount--;
    }
    while (left) {
      res = (res * left) % mod;
      left--;
    }
    return res;
  }
};

int main() {
//   int val = pow(10, 9) + 7;
    Solution sol;
    int res = sol.numPrimeArrangements(100);
    cout << res << endl;
  return 0;
}