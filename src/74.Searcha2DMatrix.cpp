#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) return false;
    int cols = matrix[0].size();
    if (cols == 0) return false;
    int l = 0, r = rows * cols;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      int x = mid % cols, y = mid / cols;
      int find = matrix[y][x];
      if (find == target)
        return true;
      else if (find > target) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return false;
  }
};