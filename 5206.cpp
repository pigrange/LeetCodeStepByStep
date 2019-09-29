#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  string removeDuplicates(string s, int k) {
    if (k == 1 || s.empty()) return "";
    stack<int> counts;
    string path = "";
    char cur = 0;
    int curCount = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      path.push_back(c);

      if (cur == 0) {
        cur = c;
        curCount++;
        continue;
      }
      if (c == cur) {
        curCount++;
        if (curCount == k) {
          for (int i = 0; i < k; i++) path.pop_back();
        }
        if (counts.empty()) {
          curCount = 0;
          cur = 0;
        } else {
          curCount = counts.top();
          counts.pop();
          cur = *--path.end();
        }
      } else {
        counts.push(curCount);
        cur = c;
        curCount = 1;
      }
    }
    return path;
  }
};