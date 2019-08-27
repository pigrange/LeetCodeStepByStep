#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string temp = "";
    solve(s, 0, res, temp, 4);
    return res;
  }

 private:
  void solve(string &s, int pos, vector<string> &res, string temp, int count) {
    if (count == 0) {
      if (pos == s.size()) {
        temp.pop_back();
        res.push_back(temp);
      }
      return;
    }
    int val = 0;
    for (int i = 0; i <= 3 && pos < s.size(); i++) {
      val = val * 10 + s[pos] - '0';
      temp.push_back(s[pos++]);
      if (val < 256) solve(s, pos, res, temp + '.', count - 1);
      if (val == 0) break;
    }
  }
};

int main() {
  string in = "11111";
  Solution sol;
  vector<string> res = sol.restoreIpAddresses(in);
  for (auto i : res) cout << i << endl;
  return 0;
}