#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int res = 0;
    for (int y = 0; y < grid.size(); y++) {
      for (int x = 0; x < grid[0].size(); x++) {
        if (grid[y][x] == '1') res += bfs(grid, y, x);
      }
    }
    return res;
  }

 private:
  int bfs(vector<vector<char>>& gird, int y1, int x1) {
    queue<pair<int, int>> q;
    q.push({y1, x1});
    while (!q.empty()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();
      gird[y][x] = '#';
      if (y + 1 < gird.size() && gird[y + 1][x] == '1') q.push({y + 1, x});
      if (x + 1 < gird[0].size() && gird[y][x + 1] == '1') q.push({y, x + 1});
      if (y - 1 >= 0 && gird[y - 1][x] == '1') q.push({y - 1, x});
      if (x - 1 >= 0 && gird[y][x - 1] == '1') q.push({y, x - 1});
    }
    return 1;
  }
};