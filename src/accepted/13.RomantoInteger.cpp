#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int romanToInt(string s) {
    int i = s.size();
    int result = 0;
    while (i-- >= 0) {
      switch (s[i]) {
        case 'I':
          result += 1;
          break;
        case 'V':
          result += 5;
          if (i > 0 && s[i - 1] == 'I') {
            result -= 1;
            i--;
          }
          break;
        case 'X':
          result += 10;
          if (i > 0 && s[i - 1] == 'I') {
            result -= 1;
            i--;
          }
          break;
        case 'L':
          result += 50;
          if (i > 0 && s[i - 1] == 'I') {
            result -= 10;
            i--;
          }
          break;
        case 'C':
          result += 100;
          if (i > 0 && s[i - 1] == 'I') {
            result -= 10;
            i--;
          }
          break;
        case 'D':
          result += 500;
          if (i > 0 && s[i - 1] == 'I') {
            result -= 100;
            i--;
          }
          break;
        case 'M':
          result += 1000;
          if (i > 0 && s[i - 1] == 'I') {
            result -= 100;
            i--;
          }
          break;
        default:
          break;
      }
    }
  }
};