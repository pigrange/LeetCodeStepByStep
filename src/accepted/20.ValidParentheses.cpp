#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    vector<char> stack;
    int ptr = -1;
    for (int i = 0; i < s.length(); i++) {
      switch (s[i]) {
        case '(':
        case '[':
        case '{':
          stack.push_back(s[i]);
          ptr++;
          break;
        case ')':
          if (ptr > -1 && stack[ptr] == '(') {
            stack.pop_back();
            ptr--;
            break;
          } else {
            return false;
          }
        case ']':
          if (ptr > -1 && stack[ptr] == '[') {
            stack.pop_back();
            ptr--;
            break;
          } else {
            return false;
          }
        case '}':
          if (ptr > -1 && stack[ptr] == '{') {
            stack.pop_back();
            ptr--;
            break;
          } else {
            return false;
          }
      }
    }
    return stack.size() == 0;
  }
};

int main() {
  //   string s = "()";
  string s = "]";
  Solution sol;
  int result = sol.isValid(s);
  cout << result << endl;
  return 0;
}