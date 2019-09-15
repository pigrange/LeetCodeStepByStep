#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    char ref[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      int pos = s[i] - 'a';
      if (ref[pos]) {
        if (ref[pos] != t[i]) return false;
      } else {
        ref[pos] = t[i];
      }
    }
    return true;
  }
};