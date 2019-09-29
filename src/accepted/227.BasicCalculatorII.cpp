#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  int calculate(string s) {
    vector<int> ref;
    vector<char> ops;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') continue;
      if (s[i] == '*' || s[i] == '/') {
        int num1 = *--ref.end();
        ref.pop_back();

        int k = i + 1;
        while (s[k] == ' ') k++;
        int l = k + 1, num2 = s[k] - '0';
        while (s[l] <= '9' && s[l] >= '0') {
          num2 = num2 * 10 + s[l] - '0';
          l++;
        }
        num2 = s[k] - '0';
        if (s[i] == '*') ref.push_back(num1 * num2);
        if (s[i] == '/') ref.push_back(num1 / num2);
        i = l;
        continue;
      }
      if (s[i] <= '9' && s[i] >= '0') {
        int base = s[i] - '0', l = i + 1;
        while (s[l] <= '9' && s[l] >= '0') {
          base = base * 10 + s[l] - '0';
          l++;
        }
        ref.push_back(base);
      } else {
        ops.push_back(s[i]);
      }
    }
    int res = ref[0];
    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == '-') res = res - ref[i + 1];
      if (ops[i] == '+') res = res + ref[i + 1];
    }
    return res;
  }
};