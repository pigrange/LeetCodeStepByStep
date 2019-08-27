#include <iostream>
#include <vector>
using namespace std;
class Solution {
  vector<bool> use1, use2, use3;

 public:
  int totalNQueens(int n) {
    use1 = vector<bool>(n, false);
    use2 = vector<bool>(2 * n, false);
    use3 = vector<bool>(2 * n, false);
    return solve(0, n);
  }

 private:
  int solve(int row, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (use1[i] || use2[n + row - i] || use3[row + i]) continue;
      use1[i] = true;
      use2[n + row - i] = true;
      use3[row + i] = true;
      if (row == n - 1)
        res = 1;
      else
        res += solve(row + 1, n);
      use1[i] = false;
      use2[n + row - i] = false;
      use3[row + i] = false;
    }
    return res;
  }
};

int main() {
  Solution sol;
  int res = sol.totalNQueens(6);
  return 0;
}