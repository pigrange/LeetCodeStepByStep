#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    //初始化ref,用角标做key
    vector<vector<int>> res;
    vector<int> temp;
    // start初始值是1
    solve(1, res, temp, n, k);
    return res;
  }

 private:
  void solve(int start, vector<vector<int>>& res, vector<int>& current, int n,
             int k) {
    if (k == 0) {
      res.push_back(current);
      return;
    }
    for (int i = start; i <= n; i++) {
      current.push_back(i);
      solve(i + 1, res, current, n, k - 1);
      current.pop_back();
    }
  }
};

// class Solution {
//  public:
//   vector<vector<int>> combine(int n, int k) {
//     vector<vector<int>> res;
//     int i = 0;
//     vector<int> p(k, 0);
//     while (i >= 0) {
//       p[i]++;
//       if (p[i] > n)
//         --i;
//       else if (i == k - 1)
//         res.push_back(p);
//       else {
//         ++i;
//         p[i] = p[i - 1];
//       }
//     }
//     return res;
//   }
// };

int main() {
  Solution sol;
  sol.combine(4, 2);
  return 0;
}