#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    unordered_map<int, string> map;
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";
    vector<string> res;
    if(res.size()!=0)dfs("", digits, map, 0, res);
    return res;
  }

 private:
  void dfs(string pre, string digits, unordered_map<int, string>& map, int pos,
           vector<string>& res) {
    if (pos == digits.size()) {
      res.push_back(pre);
      return;
    };
    int key = digits[pos] - 48;
    string current = map[key];
    for (int i = 0; i < current.size(); i++) {
      dfs(pre + current[i], digits, map, pos + 1, res);
    }
  }
};

int main() {
  Solution sol;
  string dig = "23";
  vector<string> res = sol.letterCombinations(dig);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}