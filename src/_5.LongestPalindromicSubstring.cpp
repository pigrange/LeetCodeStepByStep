#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    // start用于记录 subString 的开始的位置
    int n = s.length(), start = 0, maxLen = 1;
    bool dp[n][n] = {false};

    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
      //如果出现两个连续相同的字符
      if (i + 1 < n && s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        start = i;
        maxLen = 2;
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 2; j < n; j++) {
        // dp[i+1][j-1]表示i+1 至 j-1是一个回文
        if (dp[i + 1][j - 1] && s[i] == s[j]) {
          dp[i][j] = true;
          if (j - i >= maxLen) {
            start = i;
            maxLen = j - i + 1;
          }
        }
      }
    }

    return s.substr(start, maxLen);
  }
};
