#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> ref(n, 0);
    ref[0] = 1;
    ref[1] = 2;
    for (int i = 2; i < n; i++) ref[i] = ref[i - 1] + ref[i - 2];
    return ref[n - 1];
  }
};