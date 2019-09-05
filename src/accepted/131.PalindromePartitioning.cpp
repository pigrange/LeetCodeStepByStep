#include <iostream>
#include <vector>
using namespace std;

class Solution {
  vector<vector<string>> res;

 public:
  vector<vector<string>> partition(string s) {
    vector<string> temp;
    solve(s, 0, temp);
    return res;
  }

 private:
  void solve(string& s, int start, vector<string>& temp) {
    if (start == s.size()) {
      res.push_back(temp);
    }
    for (int i = start; i < s.size(); i++) {
      if (isPalindrome(s, start, i)) {
        temp.push_back(s.substr(start, i - start + 1));
        solve(s, i, temp);
        temp.pop_back();
      }
    }
  }

  bool isPalindrome(string& s, int l, int r) {
    while (l <= r) {
      if (s[l] != s[r]) return false;
      ++l;
      --r;
    }
    return true;
  }
};