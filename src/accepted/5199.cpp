#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    vector<vector<char>> ref(s.size(), vector<char>(s.size(), '0'));
    for (auto i : pairs) ref[i[0]][i[1]] = '1';
    // for(auto i:ref){
    //     for(auto j:i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // quickSort(s, 0, s.size() - 1, ref);
    for (int i = 0; i < s.size() - 1; i++) {
      for (int j = 0; s.size() - 1 - i; j++) {
        if (s[i] > s[i + 1] && canSwap(i, i + 1, ref)) {
          swap(s[i], s[i + 1]);
        }
      }
    }
    return s;
  }

 private:
  void quickSort(string& s, int l, int r, vector<vector<char>>& ref) {
    if (r <= l) return;
    int p = l, start = l, end = r;
    while (l < r) {
      while (l < r && s[r] >= s[p]) r--;
      if (canSwap(p, r, ref) && l < r) {
        swap(s[r], s[p]);
      }
      p = r;
      l++;
      while (l < r && s[l] <= s[p]) l++;
      if (canSwap(p, l, ref) && l < r) {
        swap(s[l], s[p]);
      }
      p = l;
      r--;
    }
    // cout << s <<endl;
    // cout << "l is " << l << "r is " << r <<endl <<endl;
    quickSort(s, start, l - 1, ref);
    quickSort(s, l + 1, end, ref);
  }
  bool canSwap(int l, int r, vector<vector<char>>& ref) {
    return ref[l][r] == '1' || ref[r][l] == '1';
  }
};