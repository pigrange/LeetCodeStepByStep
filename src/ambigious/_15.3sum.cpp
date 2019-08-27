#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& num) {
    vector<vector<int>> res;
    if (num.size() < 3) return res;
    int len = num.size();
    sort(num.begin(), num.end());
    for (int i = 0; i < len - 2; i++) {
      if (i > 0 && num[i] == num[i - 1]) continue;
      if (num[i] + num[i + 1] + num[i + 2] > 0) break;
      if (num[i] + num[len - 1] + num[len - 2] < 0) continue;
      int temp = num[i];
      int l = i + 1, r = len - 1;
      while (l < r) {
        if (num[l] + num[r] > -temp) {
          r--;
        } else if (num[l] + num[r] < -temp)
          l++;
        else {
          vector<int> v;
          v.push_back(temp);
          v.push_back(num[l]);
          v.push_back(num[r]);
          res.push_back(v);
          while (l < r && num[l] == v[1]) l++;
          while (l < r && num[r] == v[2]) r--;
        }
      }
    }
    return res;
  }
};
int main() {
  //   vector<int> nums = {-2, 0, 0, 2, 2};
  vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  Solution sol;
  vector<vector<int>> res = sol.threeSum(nums);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ,";
    }
    cout << endl;
  }
}