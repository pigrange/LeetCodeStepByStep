#include <iostream>
#include <vector>
using namespace std;
// class Solution {
//  public:
//   int minDistance(string word1, string word2) {
//     int pt = 0, n = word1.size(), m = word2.size(), res = m;
//     // int *refs = new int[n];
//     for (int p1 = 0; p1 < n; p1++) {
//       for (int p2 = 0; p2 < m; p2++) {
//         if (word1[p1] == word2[p2]) {
//           if (p2 > pt) res -= 1;
//           pt = p2;
//           break;
//         }
//       }
//       res += 1;
//       //   refs[p1] = res;
//       cout << "temp res is : " << res << endl;
//     }
//     return res;
//   }
// };

class Solution {
 public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> ref(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) ref[i][0] = i;
    for (int i = 1; i <= n; i++) ref[0][i] = i;
    for (int y = 1; y <= m; y++) {
      for (int x = 1; x <= n; x++) {
        if (word1[x - 1] == word2[y - 1]) {
          ref[y][x] = ref[y - 1][x - 1];
        } else {
          ref[y][x] = min(min(ref[y - 1][x - 1], ref[y - 1][x]), ref[y][x - 1]) + 1;
        }
      }
    }
    return ref[m][n];
  }
};

int main() {
  string word1 = "intention";
  string word2 = "execution";
  Solution sol;
  int res = sol.minDistance(word1, word2);
  cout << "res is " << res << endl;
  return 0;
}