#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

class Solution {
 public:
  void replaceSpace(char *str, int length) {
    std::string res = "";
    for (int i = 0; i < length; i++) {
      if (str[i] != ' ') {
        res.push_back(str[i]);
      } else {
        res.push_back('%');
        res.push_back('2');
        res.push_back('0');
      }
    }
    auto ret = res.c_str();
    strcpy(str, ret);
  }
};
int main() {
  char *str = "hello world";

  Solution sol;
  sol.replaceSpace(str, 11);
  std::string res = std::string(str);
  std::cout << res << std::endl;
  return 0;
}