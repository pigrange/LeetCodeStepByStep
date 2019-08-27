#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> ref(n, vector<int>(m, 0));
    ref[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 && j == 0) continue;
        if (j > 0) ref[i][j] += ref[i][j - 1];
        if (i > 0) ref[i][j] += ref[i - 1][j];
      }
    }
    return ref[n - 1][m - 1];
  }
};