#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int lpos = 0, rpos = 1, p = rpos;
    int minH = min(height[lpos], height[rpos]);
    int maxArea = minH;
    while (p++ < height.size()) {
      int newHeight = height[p];
      if (newHeight > minH) {
        maxArea =
            max(minH * (rpos - lpos + 1), height[lpos + 1] * (rpos - lpos));
      } else {
      }
    }
  }
};