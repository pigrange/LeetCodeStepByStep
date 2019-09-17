#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    unordered_map<int, int> ref;
    if (s.size() < 10) return res;
    int hash = 0;
    for (int i = 0; i < s.size(); i++) {
      hash = ((hash << 2) & (0xFFFFF)) + getBits(s[i]);
      if (i < 9) continue;
      ref[hash]++;
      if (ref[hash] == 2) res.push_back(s.substr(i - 9, 10));
    }
    return res;
  }

 private:
  int getBits(char ch) {
    switch (ch) {
      case 'A':
        return 0;  // 00
      case 'C':
        return 1;  // 01
      case 'G':
        return 2;  // 10
      case 'T':
        return 3;  // 11
    }
    return 0;
  }
};