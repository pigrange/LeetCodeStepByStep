#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (!matrix.size() || !matrix[0].size()) return 0;
    char res = '0';
    for (int y = 0; y < matrix.size(); y++) {
      for (int x = 0; x < matrix[0].size(); x++) {
        if (y == 0 || x == 0) {
          res = max(res, matrix[y][x]);
          continue;
        }
        if (matrix[y][x] == '1') {
          char m = min(matrix[y - 1][x - 1], matrix[y - 1][x]);
          m = min(matrix[y][x - 1], m);
          matrix[y][x] = m + 1;
          res = max(res, matrix[y][x]);
        }
      }
    }
    for (auto row : matrix) {
      for (auto i : row) cout << i;
      cout << endl;
    }
    return (res - '0') * (res - '0');
  }
};