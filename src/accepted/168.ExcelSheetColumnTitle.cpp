#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  string convertToTitle(int n) {
    string res = "";
    while (n >= 0) {
      int num = n % 26;
      res.push_back(num - 1 + 'A');
      n = n / 26;
    }
    return res;
  }
};
