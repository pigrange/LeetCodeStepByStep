#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    bool firstRowZero = false;
    int rows = matrix.size(), cols = matrix[0].size();
    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        if (matrix[y][x] == 0) {
          if (y == 0) {
            firstRowZero = true;
            break;
          }
          matrix[y][0] = 0;
          matrix[0][x] = 0;
        }
      }
    }
    //先将行全部设置为0
    for (int i = 1; i < rows; i++) {
      if (matrix[i][0] == 0)
        for (int j = 1; j < cols; j++) matrix[i][j] = 0;
    }

    //将列全部设置为0
    for (int i = 0; i < cols; i++) {
      if (matrix[0][i] == 0)
        for (int j = 1; j < rows; j++) matrix[j][i] = 0;
    }

    if (firstRowZero)
      for (int i = 0; i < cols; i++) matrix[0][i] = 0;
  }
};