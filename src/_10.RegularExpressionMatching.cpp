#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    if ('*' == p[1])
      return (isMatch(s, p.substr(2)) || !s.empty() &&
                                             (s[0] == p[0] || '.' == p[0]) &&
                                             isMatch(s.substr(1), p));
    else
      return !s.empty() && (s[0] == p[0] || '.' == p[0]) &&
             isMatch(s.substr(1), p.substr(1));
  }
};

class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
    f[0][0] = true;
    //把第一列全部设置为false
    //第一列代表了s为""的时候，任何情况都无法匹配
    for (int i = 1; i <= m; i++) f[i][0] = false;
    //初始化第一行的值,第一行表示s为""。
    // j的满足条件".*"或"a*b*c*d*"这种
    for (int j = 1; j <= n; j++) f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];  //这个f[0][j-2]秒啊！！！

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        //先遍历行
        if (p[j - 1] != '*')
          f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
        else
          f[i][j] = f[i][j - 2] ||(s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

    return f[m][n];
  }
};