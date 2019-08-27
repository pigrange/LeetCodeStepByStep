#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// DP解法，妈的，想不出来
//穷举法？？？，带剪枝，因为如果右边比左边大的话，带右边的一定比不带
//右边的大，所以，直接找到极大值点开始向前进行计算
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    int res = 0, len = heights.size();
    for (int i = 0; i < len; i++) {
      //出现了极大值点
      if (i + 1 < len && heights[i] <= heights[i + 1]) continue;
      int minH = heights[i];
      for (int j = i; j >= 0; j--) {
        minH = min(minH, heights[j]);
        int area = minH * (i - j + 1);
        res = max(res, area);
      }
    }
    return res;
  }
};

//神仙解法
class Solution {
 public:
  int largestRectangleArea(vector<int>& height) {
    height.push_back(0);
    int n = height.size(), area = 0;
    stack<int> indexes;
    for (int i = 0; i < n; i++) {
      while (!indexes.empty() && height[indexes.top()] > height[i]) {
        int h = height[indexes.top()];
        indexes.pop();
        int l = indexes.empty() ? -1 : indexes.top();
        area = max(area, h * (i - l - 1));
      }
      indexes.push(i);
    }
    return area;
  }
};

