#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int len = matrix.size(), level = len / 2;
    for (int i = 0; i < level; i++) {
      int size = len - 2 * i, temp;
      for (int j = 0; j < size - 1; j++) {
        //将left copy到temp里面·
        //第i列的第j+i行
        temp = matrix[j + i][i];
        //将bottom copy到left里面
        //第len - i - 1 行的 第 i+j列
        matrix[j + i][i] = matrix[len - 1 - i][j + i];
        //将right copy到bottom里
        //第len - i - 1 列的第 len - i - 1 - j 行
        matrix[len - 1 - i][j + i] = matrix[len - i - 1 - j][len - i - 1];
        //将top copy到right里
        matrix[len - i - 1 - j][len - i - 1] = matrix[i][len - i - 1 - j];
        //将temp copy到top里
        matrix[i][len - i - 1 - j] = temp;
      }
    }
  }
};

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};