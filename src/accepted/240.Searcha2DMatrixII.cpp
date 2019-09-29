#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    for (int i = 0; i < matrix.size(); i++) {
      vector<int>& t = matrix[i];
      if (t[t.size() - 1] < target) continue;
      int l = 0, r = t.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (t[m] == target) return true;
        if (t[m] > target) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    return false;
  }
};

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) return false;
    int n = matrix[0].size() - 1;
    int m = 0;
    while (m < matrix.size() && n >= 0) {
      if (matrix[m][n] == target)
        return true;
      else if (matrix[m][n] < target)
        ++m;
      else
        --n;
    }
    return false;
  }
};

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    if (target < matrix[0][0] || target > matrix.back().back()) return false;
    int x = matrix.size() - 1, y = 0;
    while (true) {
      if (matrix[x][y] > target)
        --x;
      else if (matrix[x][y] < target)
        ++y;
      else
        return true;
      if (x < 0 || y >= matrix[0].size()) break;
    }
    return false;
  }
};