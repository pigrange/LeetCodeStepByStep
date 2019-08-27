#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<long> ref(rowIndex + 1, 1);
    vector<int> res = {1};
    int len = rowIndex + 1;
    for (int i = 1; i < len; i++) {
      for (int j = 1; j < len; j++) {
        ref[j] = ref[j] + ref[j - 1];
      }
      res.push_back(ref[rowIndex - i]);
    }
    return res;
  }
};