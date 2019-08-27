#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int x = 0, y = 0, pos = 0;
    for (int i = 0; i < n * n; i++) {
      res[y][x] = i + 1;
      //切换方向的判断逻辑
      //可达并且等于0
      int x1 = x + dirs[pos][0], y1 = y + dirs[pos][1];
      if (0 <= x1 && x1 < n && 0 <= y1 && y1 < n && res[y1][x1] == 0) {
        x = x1;
        y = y1;
      } else {
        pos = (pos + 1) % 4;
        x += dirs[pos][0];
        y += dirs[pos][1];
      }
    }
    return res;
  }
};
int main() {
  Solution sol;
  vector<vector<int>> res = sol.generateMatrix(1);
  for (auto row : res) {
    for (auto i : row) cout << i << " ";
    cout << endl;
  }
  return 0;
}