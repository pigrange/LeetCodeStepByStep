#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  string reverseParentheses(string s) {
    stack<int> op, co;
    string res = "";
    int pushCount = 0, offset = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        op.push(i);
        co.push(offset);
        offset++;
        continue;
      }
      if (s[i] == ')') {
        int pre = op.top();
        op.pop();
        int count = co.top();
        co.pop();
        offset++;
        int begin = pre - count;
        int end = i - offset + 1;
        reverse(res.begin() + begin, res.begin() + end + 1);
        cout << "pre is " << begin << "end is " << end << endl;
        continue;
      }
      res.push_back(s[i]);
    }
    return res;
  }
};