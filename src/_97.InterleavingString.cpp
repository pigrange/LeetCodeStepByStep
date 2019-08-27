#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));
    dp[0][0] = true;
    //先处理第一列
    for (int i = 1; i <= n1; ++i) {
      dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }
    //再处理第一行
    for (int i = 1; i <= n2; ++i) {
      dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
    }
    //最后处理其他的位置
    //两种情况
    // ->1: s3的第i+j个字符是否来自于s1的第i个字符,或者s2的第j个字符
    for (int i = 1; i <= n1; ++i) {
      for (int j = 1; j <= n2; ++j) {
        dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) ||
                   (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
      }
    }
    return dp[n1][n2];
  }
};