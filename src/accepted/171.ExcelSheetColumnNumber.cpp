#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int titleToNumber(string s) {
    int res = 0;
    while (!s.empty()) {
      char ch = *--s.end();
      s.pop_back();
      res = res * 26 + ch - 'A' + 1;
    }
    return res;
  }
};
