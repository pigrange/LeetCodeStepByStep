#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
 public:
  bool isHappy(int n) {
    unordered_map<int, int> ref;
    while (!ref.count(n)) {
      ++ref[n];
      int new_n = 0;
      while (n > 0) {
        int t = n % 10;
        new_n += t * t;
        n = n / 10;
      }
      if (new_n == 1) return true;
    }
    return false;
  }
};