#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int trailingZeroes(int n) {
    int result = 0;
    for (long long i = 5; n / i > 0; i *= 5) {
      result += (n / i);
    }
    return result;
  }
};

//本来来说，n/5就可以了/
//但是由于有5的幂次项需要单独考虑
//比如说55，就包含了25。25会多一个5出来
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};