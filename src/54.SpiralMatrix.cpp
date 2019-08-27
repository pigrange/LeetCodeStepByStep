#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int dir = 0, n = matrix.size();
    vector<int> res;
    if (n == 0) return res;
    int i = 0, j = 0, count = 1, m = matrix[0].size();
    while (count < m * n) {
      //向右跑
      if (dir == 0 && i + 1 < m && matrix[j][i + 1] != INT32_MIN) {
        res.push_back(matrix[j][i]);
        matrix[j][i++] = INT32_MIN;
      } else if (dir == 1 && j + 1 < n && matrix[j + 1][i] != INT32_MIN) {
        res.push_back(matrix[j][i]);
        matrix[j++][i] = INT32_MIN;
      } else if (dir == 2 && i > 0 && matrix[j][i - 1] != INT32_MIN) {
        res.push_back(matrix[j][i]);
        matrix[j][i--] = INT32_MIN;
      } else if (dir == 3 && j > 0 && matrix[j - 1][i] != INT32_MIN) {
        res.push_back(matrix[j][i]);
        matrix[j--][i] = INT32_MIN;
      } else {
        dir = (dir + 1) % 4;
        continue;
      }
      count++;
    }
    res.push_back(matrix[j][i]);
    return res;
  }
};

int main() {
  Solution sol;
  //   vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  //   vector<vector<int>> matrix = {{1, 2}, {3, 4}};
  vector<vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<int> res = sol.spiralOrder(matrix);
  for (auto i : res) cout << i << " ";
  return 0;
}