#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// DP2
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n - 2; layer >= 0; layer--) {
      for (int i = 0; i <= layer; i++) {
        minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
      }
    }
    return minlen[0];
  }
};

// DP1
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = 1; i < triangle.size(); ++i) {
      for (int j = 0; j < triangle[i].size(); ++j) {
        if (j == 0) {
          triangle[i][j] += triangle[i - 1][j];
        } else if (j == triangle[i].size() - 1) {
          triangle[i][j] += triangle[i - 1][j - 1];
        } else {
          triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
      }
    }
    return *min_element(triangle.back().begin(), triangle.back().end());
  }
};