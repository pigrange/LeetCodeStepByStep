#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (int i = 0; i < intervals.size(); i++) {
      if (i == intervals.size() - 1) {
        res.push_back(intervals[i]);
        break;
      }
      vector<int> &sub1 = intervals[i];
      vector<int> &sub2 = intervals[i + 1];
      if (sub1[1] < sub2[0]) {
        res.push_back(sub1);
        continue;
      }
      sub1[1] = max(sub1[1], sub2[1]);
      swap(sub1, sub2);
    }
    return res;
  }
};