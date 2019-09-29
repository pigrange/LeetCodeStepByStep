#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int min_val = INT32_MAX;
    vector<vector<int>> res;
    for (int i = 0; i < arr.size() - 1; i++) {
      int t = abs(arr[i + 1] - arr[i]);
      if (!(t > min_val)) {
        if (t < min_val) res.clear();
        res.push_back({arr[i], arr[i + 1]});
        min_val = t;
      }
    }
    return res;
  }
};