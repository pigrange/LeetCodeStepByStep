#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  string multiply(string num1, string num2) {
    int len = num1.size() + num2.size();
    char res[len + 1];
    res[len] = 0;
    memset(res, 48, len);
    int nextGen, head = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
      nextGen = 0;
      for (int j = num2.size() - 1; j >= 0; j--) {
        int pos = i + j + 1;
        int temp = res[pos] - '0' + (num1[i] - 48) * (num2[j] - 48) + nextGen;
        nextGen = temp / 10;
        temp = temp % 10;
        res[pos] = temp + '0';
      }
      if (nextGen != 0) res[i] += nextGen;
    }
    while (res[head] == '0' && head < len - 1) head++;
    char* ref = res;
    return string(ref + head);
  }
};

int main() {
  //   string num1 = "99999999";
  string num1 = "9133";
  //   string num2 = "99999999";
  string num2 = "0";
  Solution sol;
  string res = sol.multiply(num1, num2);
  cout << "Res is " << res << endl;
  return 0;
}