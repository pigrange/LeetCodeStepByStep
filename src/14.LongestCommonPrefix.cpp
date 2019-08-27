#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string pre = "";
    if (strs.size() == 0) return "";
    if (strs.size() == 1) return strs[0];
    for (int i = 0; i < strs[0].length(); i++) {
      for (int j = 1; j < strs.size(); j++) {
        if (strs[j][i] != strs[0][i]) {
          return pre;
        }
      }
      pre.push_back(strs[0][i]);
    }
    return pre;
  }
};

int main() {
  // vector<string> strs = {"flower", "flow", "flight"};
  vector<string> strs = {"dog", "racecar", "car"};
  Solution sol;
  string res = sol.longestCommonPrefix(strs);
  cout << res << endl;
  return 0;
}