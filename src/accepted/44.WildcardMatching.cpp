#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int slen = s.size(), plen = p.size();
    vector<vector<bool>> ref(plen + 1, vector<bool>(slen + 1, false));
    ref[0][0] = 1;
    for (int y = 0; y < plen; y++) {
      ref[y + 1][0] = (p[y] == '*' && ref[y][0]);
      for (int x = 0; x < slen; x++) {
        if (s[x] == p[y] || p[y] == '?')
          ref[y + 1][x + 1] = ref[y][x];
        else if (p[y] == '*') {
          ref[y + 1][x + 1] = ref[y][x] || ref[y][x + 1] || ref[y + 1][x];
        }
      }
    }
    return ref[plen][slen];
  }
};