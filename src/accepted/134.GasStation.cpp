#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    for (int i = 0; i < len; i++) {
      if (gas[i] < cost[i]) continue;
      int temp = 0;
      for (int j = 0; j < len; j++) {
        int pos = (j + i) % len;
        temp += gas[pos] - cost[pos];
        if (temp < 0) break;
      }
      if (temp >= 0) return i;
    }
    return -1;
  }
};

class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    // left记录负数，acc记录正数
    int left = 0, acc = 0, startPos = -1;
    for (int i = 0; i < len; i++) {
      int t = acc + gas[i] - cost[i];
      if (t < 0) {
        left += t;
        acc = 0;
        startPos = -1;
      } else {
        if (startPos == -1) startPos = i;
        acc = t;
      }
    }
    return acc - left >= 0 ? startPos : -1;
  }
};