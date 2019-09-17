#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int ref[5] = {0};
    for (auto i : text) {
      int pos = getpos(i);
      if (pos >= 0) ref[pos]++;
    }
    int res = INT32_MAX;
    for (int i = 0; i < 3; i++) {
      res = min(res, ref[i]);
    }
    for (int i = 3; i <= 4; i++) {
      res = min(res, ref[i] / 2);
    }
    return res;
  }

 private:
  int getpos(char ch) {
    switch (ch) {
      case 'b':
        return 0;
      case 'a':
        return 1;
      case 'n':
        return 2;
      case 'l':
        return 3;
      case 'o':
        return 4;
      default:
        return -1;
    }
  }
};