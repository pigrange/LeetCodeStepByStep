#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int buy = 0, sale = 0, res = 0;
    for (int i = 1; i < prices.size(); i++) {
      if (i < prices.size() - 1 && prices[i] > prices[i - 1]) {
        if (prices[buy] > prices[i]) buy = i;
      } else {
        if (prices[sale] < prices[i]) sale = i;
      }
      if (sale > buy) res = max(res, prices[sale] - prices[buy]);
    }
    return res;
  }
};