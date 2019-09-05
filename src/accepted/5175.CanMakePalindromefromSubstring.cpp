#include <iostream>
#include <vector>
using namespace std;

// class Solution {
//  public:
//   vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
//     vector<bool> res;
//     vector<bool> ref(26, false);
//     for (auto cur : queries) {
//       int l = cur[0], r = cur[1], k = cur[2], count = 0;
//       for (int i = l; i <= r; i++) ref[s[i] - 'a'] = !ref[s[i] - 'a'];
//       for (int i = 0; i < ref.size(); i++) {
//         if (ref[i]) {
//           ref[i] = false;
//           count++;
//         }
//       }
//       count = count / 2;
//       bool t = (count <= k);
//       res.push_back(t);
//     }
//     return res;
//   }
// };

class Solution {
 public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int len = s.size();
    vector<bool> res;
    vector<vector<int>> ref(len + 1, vector<int>(26, 0));

    for (int i = 0; i < s.size(); i++) {
      ref[i + 1] = ref[i];
      ++ref[i + 1][s[i] - 'a'];
    }
    for (auto q : queries) {
      int count = 0;
      //统计每一个字符的差
      for (int j = 0; j < 26; j++) {
        //某一个字符出现了奇数次数
        count += (ref[q[1] + 1][j] - ref[q[0]][j]) % 2;
      }
      res.push_back(count / 2 <= q[2]);
    }
    return res;
  }
};

int main() {
  // s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
  string s = "abcda";
  vector<vector<int>> queries = {
      {3, 3, 0}, {1, 2, 0}, {0, 3, 1}, {0, 3, 2}, {0, 4, 1}};
  Solution sol;
  vector<bool> res = sol.canMakePaliQueries(s, queries);
  for (auto i : res) cout << i << endl;
  return 0;
}