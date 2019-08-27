#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int pos = digits.size() - 1;
    digits[pos] += 1;
    while (pos > 0) {
      if (digits[pos] == 10) {
        digits[pos] = 0;
        digits[pos - 1] += 1;
      } else {
        return digits;
      }
      pos--;
    }
    if (digits[0] == 10) {
      digits[0] = 1;
      digits.push_back(0);
    }
    return digits;
  }
};