#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      if (!isValidate(s[l])) {
        ++l;
        continue;
      }
      if (!isValidate(s[r])) {
        --r;
        continue;
      }
      if (s[l] != s[r])
        return false;
      else {
        ++l;
        --r;
      }
    }
    return true;
  }

 private:
  bool isValidate(char& ch) {
    if ('A' <= ch && ch <= 'Z') ch = ch + 32;
    return ('0' <= ch && ch <= '9' && ch <= 'z' && 'a' <= ch);
  }
};