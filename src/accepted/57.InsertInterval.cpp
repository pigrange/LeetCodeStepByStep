#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    bool flag = true;
    if (intervals.size() == 0) return {newInterval};
    vector<vector<int>> res;
    for (int i = 0; i < intervals.size(); i++) {
      vector<int>& sub1 = intervals[i];
      //如果newInterval区间比现在的区间小的话，就将res，push进去
      if (flag && newInterval[1] < sub1[0]) {
        res.push_back(newInterval);
        flag = false;
        i--;
        continue;
      }
      //如果两个区间有交集，就直接插入
      if (flag && newInterval[0] <= sub1[1]) {
        sub1[0] = min(sub1[0], newInterval[0]);
        sub1[1] = max(sub1[1], newInterval[1]);
        flag = false;
      }
      if (i == intervals.size() - 1) {
        res.push_back(intervals[i]);
        if (flag) res.push_back(newInterval);
        break;
      }
      vector<int>& sub2 = intervals[i + 1];
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
