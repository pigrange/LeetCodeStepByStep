#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int numTrees(int n) {
    if (n == 0) return 0;
    int *ref = new int[n + 1]{0};
    ref[0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        ref[i] += ref[j - 1] * ref[i - j];
      }
    }
    return ref[n];
  }
};

int main() {
  Solution sol;
  int res = sol.numTrees(1);
  cout << "res is " << res << endl;
  return 0;
}