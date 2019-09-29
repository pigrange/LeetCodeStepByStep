#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    int l = 0, r = 0, len = s.size(), step = 0, res = 0, refCost = maxCost;
    while (r < len) {
      int cost = abs(s[r] - t[r]);
      if (cost <= maxCost) {
        step++;
        maxCost -= cost;
        res = max(step, res);
      } else {
        if (cost > refCost) {
          step = 0;
          l = r + 1;
        }
        while (maxCost < cost && l < r) {
          int tcost = abs(s[l] - t[l]);
          maxCost += tcost;
          step--;
          l++;
        }
        if (maxCost >= cost) continue;
      }
      r++;
    }
    return res;
  }
};