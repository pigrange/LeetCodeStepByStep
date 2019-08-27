#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int numDistinct(string s, string t) {
    vector<vector<int>> ref(t.size() + 1, vector<int>(s.size() + 1, false));
    ref[0][0] = true;
    for(int i=1;i<=s.size();i++) ref[0][i] = 1;
    for (int y = 1; y <= t.size(); y++) {
      for (int x = 1; x <= s.size(); x++) {
        if (t[y - 1] == s[x - 1]) {
          ref[y][x] = ref[y - 1][x - 1] + ref[y][x - 1];
        } else {
          ref[y][x] = ref[y][x - 1];
        }
      }
    }
    for (int y = 0; y <= t.size(); y++) {
      for (int x = 0; x <= s.size(); x++) {
        cout << ref[y][x] << " ";
      }
      cout << endl;
    }

    return ref[t.size()][s.size()];
  }
};