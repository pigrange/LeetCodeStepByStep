#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    string temp = "";
    int len = -1, pos = 0;
    for (int i = 0; i <= words.size(); i++) {
      if (i == words.size() || len + words[i].size() + 1 > maxWidth) {
        if (i == words.size()) {
          while (pos < i) {
            temp = temp + words[pos] + ' ';
            pos++;
          }
          int count = maxWidth - temp.size();
          if(count<0)temp.pop_back();
          for (int i = 0; i < count; i++) temp += ' ';
        } else {
          int spaceCount = (i - pos) - 1;
          int extra = maxWidth - len;
          int ava = spaceCount ? extra / spaceCount + 1 : extra;
          int offset = spaceCount ? extra % spaceCount : 0;
          spaceCount = spaceCount ? spaceCount : 1;
          while (pos < i) {
            temp += words[pos];
            if (spaceCount-- > 0)
              for (int k = 0; k < ava; k++) temp += ' ';
            if (offset-- > 0) temp += ' ';
            pos++;
          }
        }
        res.push_back(temp);
        temp = "";
        len = -1;
      }
      if (i < words.size()) len += words[i].size() + 1;
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<string> words = {"This",           "is", "an", "example", "of", "text",
                          "justification.", "aa"};
  sol.fullJustify(words, 16);
  return 0;
}