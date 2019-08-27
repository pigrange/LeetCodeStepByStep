#include <string.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    //初始化一个全部为0的数组
    int stackPtr = -1, len = s.size();
    int *ref = new int[len]();
    int *refPos = new int[len]();
    memset(ref, 0, len);
    char *stack = new char[len];
    for (int i = 0; i < len; i++) {
      if (s[i] == '(') {
        stack[++stackPtr] = '(';
        refPos[stackPtr] = i;
      } else if (s[i] == ')') {
        //找到了满足条件的括号组，出栈
        if (stackPtr >= 0 && stack[stackPtr] == '(') {
          ref[refPos[stackPtr]] = 1;
          ref[i] = 1;
          stackPtr--;
        }
      }
    }
    // for (int i = 0; i < len; i++) cout << ref[i] << " ";
    int res = 0;
    for (int i = 0; i < len; i++) {
      if (ref[i] == 1) {
        int p = i;
        while (p < len && ref[p] != 0) p++;
        res = max(res, p - i);
        i = p;
      }
    }
    return res;
  }
};

// DP Solution
class Solution {
 public:
  int longestValidParentheses(string s) {
    int result = 0;
    s = ')' + s;
    vector<int> dp(s.length(), 0);
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == ')') {
        if (s[i - 1 - dp[i - 1]] == '(') dp[i] = dp[i - 1] + 2;
        dp[i] += dp[i - dp[i]];
      }
      result = max(result, dp[i]);
    }
    return result;
  }
};

// Simplify Solution
class Solution {
 public:
  int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        stk.pop();
        if (stk.empty()) {
          stk.push(i);
        } else {
          ans = max(ans, i - stk.top());
        }
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  // string str = "()(())";
  //   string str = "(()())";
  string str = "(()";
  //   string str = "((((()())()()))()(()))";
  int res = sol.longestValidParentheses(str);
  cout << res << endl;
  return 0;
}