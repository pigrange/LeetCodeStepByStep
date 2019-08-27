#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string res[31];
    res[1] = "1";
    for (int i = 2; i <= n; i++) {
      string str = res[i - 1], appen = "";
      int count = 1;
      char temp = str[0];
      for (int i = 1; i < str.size(); i++) {
        if (str[i] != temp) {
          appen = appen + to_string(count) + temp;
          count = 1;
          temp = str[i];
        } else {
          count++;
        }
      }
      appen = appen + to_string(count) + temp;
      res[i] = appen;
    }
    return res[n];
  }
};

int main() {
  Solution sol;
    for (int i = 1; i <= 10; i++) {
    cout << sol.countAndSay(i) << endl;
//   //   cout << sol.countAndSay(2) << endl;
//   cout << sol.countAndSay(3) << endl;
//   cout << sol.countAndSay(4) << endl;
    }
  return 0;
}