#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++) {
      if (i == 0)
        res.push_back({1});
      else if (i == 0)
        res.push_back({1, 1});
      else {
        vector<int> temp = {1};
        for (int j = 0; j < i - 1; j++) {
          temp.push_back(res[i - 1][j] + res[i - 1][j + 1]);
        }
        temp.push_back(1);
      }
    }
    return res;
  }
};