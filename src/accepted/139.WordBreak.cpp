#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> ref(s.size() + 1, false);
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    ref[0] = true;
    for (int i = 0; i < s.size(); i++) {
      for (int j = i; j >= 0; j--) {
        if (!ref[j]) continue;
        string s = s.substr(j, i - j + 1);
        if (words.count(s)) {
          ref[i + 1] = 1;
          break;
        }
      }
    }
    return ref[s.size()];
  }
};