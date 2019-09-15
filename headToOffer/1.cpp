#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool Find(int target, vector<vector<int>> array) {
    for (int i = 0; i < array.size(); i++) {
      vector<int> &t = array[i];
      if (t[t.size() - 1] < target) continue;
      int l = 0, r = t.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (t[m] == target) return true;
        if (t[m] > target) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    return false;
  }
};
int main() {
  vector<vector<int>> ref = {
      {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
  Solution sol;
  bool res = sol.Find(1, ref);
  cout << res;
  res = sol.Find(4, ref);
  cout << res;
  res = sol.Find(10, ref);
  cout << res;
  res = sol.Find(15, ref);
  cout << res;
  return 0;
}