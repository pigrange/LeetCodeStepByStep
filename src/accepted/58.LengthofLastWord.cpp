#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int lengthOfLastWord(string s) {
    if (s.size() == 0) return 0;
    int p = s.size() - 1, q = p;
    while (q >= 0) {
      if (s[q] != ' ') break;
      q--;
    }
    p = q;
    while (q >= 0) {
      if (s[q] == ' ') break;
      q--;
    }
    return p - q;
  }
};

int main() {
  Solution sol;
  cout << "res is " << sol.lengthOfLastWord("A ");
  return 0;
}