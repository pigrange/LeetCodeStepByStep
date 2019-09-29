#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (t.size() < s.size()) return false;
    int ref[26] = {0};
    for (auto c : s) {
      ref[c - 'a']++;
    }
    for (auto c : t) {
      if (!ref[c - 'a']) return false;
      ref[c - 'a']--;
    }
    return true;
  }
};