#include <iostream>
#include <vector>
using namespace std;
class Solution {
  vector<bool> use1, use2, use3;

 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> temp;
    use1 = vector<bool>(n, 0);
    use2 = vector<bool>(2 * n, 0);
    use3 = vector<bool>(2 * n, 0);
    solve(res, 0, n, temp);
    return res;
  }

 private:
  void solve(vector<vector<string>> &res, int row, int n,
             vector<string> &temp) {
    for (int i = 0; i < n; i++) {
      //表示该列已经存在了
      if (use1[i] || use2[n + row - i] || use3[row + i]) continue;
      use1[i] = 1;
      use2[n + row - i] = 1;
      use3[row + i] = 1;
      string s = string(n, '.');
      s[i] = 'Q';
      temp.push_back(s);
      if (row == n - 1) {
        res.push_back(temp);
      } else {
        solve(res, row + 1, n, temp);
      }
      temp.pop_back();
      use1[i] = 0;
      use2[n + row - i] = 0;
      use3[row + i] = 0;
    }
  }
};

int main() {
  Solution sol;
  sol.solveNQueens(5);
  return 0;
}