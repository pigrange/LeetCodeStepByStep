#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = grid[0].size();
    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        if (y == 0) {
          if (x == 0)
            continue;
          else
            grid[y][x] += grid[y][x - 1];
        } else {
          if (x == 0)
            grid[y][x] += grid[y - 1][x];
          else
            grid[y][x] += min(grid[y - 1][x], grid[y][x - 1]);
        }
      }
    }
    return grid[row - 1][col - 1];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> res = {{1, 2, 5}, {3, 2, 1}};
  cout << "res is " << sol.minPathSum(res);
  return 0;
}