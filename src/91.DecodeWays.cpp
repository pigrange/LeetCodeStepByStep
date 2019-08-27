#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int *ref = new int[s.size() + 1];
    ref[0] = 1;
    ref[1] = 1;
    for (int i = 2; i <= s.size(); i++) {
      if (s[i - 1] == '0') {
        if (s[i - 2] == '0' || s[i - 2] > '2')
          return 0;
        else
          ref[i] = ref[i - 2];
      } else if (s[i - 2] == '0') {
        ref[i] = ref[i - 1];
      } else {
        int temp = s[i] - '0' + 10 * (s[i - 1] - '0');
        ref[i] = temp < 27 ? ref[i - 1] + ref[i - 2] : ref[i - 1];
      }
    }
    return ref[s.size()];
  }
};