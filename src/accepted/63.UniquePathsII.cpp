#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size(), col = obstacleGrid[0].size();
    vector<vector<int>> ref(row, vector<int>(col, 0));
    for (int y = 0; y < row; y++) {
      for (int x = 0; x < col; x++) {
        if (obstacleGrid[y][x]) continue;
        if (x == 0 && y == 0) {
          ref[0][0] = 1;
          continue;
        }
        if (y > 0) ref[y][x] += ref[y - 1][x];
        if (x > 0) ref[y][x] += ref[y][x - 1];
      }
    }
    return ref[row - 1][col - 1];
  }
};

int main() {
  Solution sol;
  vector<vector<int>> test = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << sol.uniquePathsWithObstacles(test);
  return 0;
}