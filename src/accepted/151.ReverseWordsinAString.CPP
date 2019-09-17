#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++) {
      //开始统计word
      if (s[i] != ' ') {
        int j = i + 1;
        for (; j < s.size(); j++) {
          if (s[j] == ' ') break;
        }
        //生成子Word
        string substr = s.substr(i, j - i);
        i = j;
        res = substr + " " + res;
      }
    }
    return res;
  }
};

// class Solution {
//  public:
//   string reverseWords(string s) {
//     istringstream is(s);
//     string tmp = "";
//     string out = "";
//     while (is >> tmp) {
//       tmp += " ";
//       tmp += out;
//       out = tmp;
//     }
//     s = out.substr(0, out.length() - 1);
//     return s;
//   }
// };

int main() {
  Solution sol;
  string test = "";
  return 0;
}