#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  string addBinary(string a, string b) {
    bool addition = 0;
    string res = "";
    int p1 = a.size() - 1, p2 = b.size() - 1, step = max(p1, p2);
    while (step >= 0) {
      int t1 = p1 >= 0 ? a[p1--] - 48 : 0;
      int t2 = p2 >= 0 ? b[p2--] - 48 : 0;
      int temp = t1 + t2 + addition;
      addition = temp > 1 ? 1 : 0;
      temp = temp % 2 + '0';
      res.push_back(temp);
      step--;
    }
    if (addition) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution sol;
  string res = sol.addBinary("11", "1");
  cout << "res is " << res << endl;
  return 0;
}