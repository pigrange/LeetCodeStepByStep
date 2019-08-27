#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  string minWindow(string s, string t) {
    int l = 0, r = 0, p = -1, count = t.size(), len = s.size(),
        width = INT32_MAX;
    unordered_map<char, int> ref;
    for (auto ch : t) {
      ref[ch] += 1;
    }
    while (r < len) {
      while (count > 0 && r < len) {
        char key = s[r];
        //如果存在这个key,
        if (ref.count(key) == 1) {
          //并且这个key理论出现的次数还没有出现完
          if (ref[key] > 0) count--;
          //但是key的出现次数还是要减去
          ref[key]--;
        }
        r++;
      }
      cout << "r is " << r << endl;
      //当count=0的时候，即t所需要的字符全部在窗口中了
      //这个时候，开始右移l
      //更新最小的窗口
      while (count == 0 && l < len) {
        //这个位置能够确保count为0，也就是说在窗口中
        if (r - l < width) {
          width = r - l;
          p = l;
        }
        cout << "p is " << p << " , "
             << "width is " << width << endl;
        // key是准备丢弃的ch
        char key = s[l];
        if (ref.count(key) == 1) {
          ref[key]++;
          //这里如果ref[key]<=0的话，即说明这个key丢弃了并没有什么影响
          if (ref[key] > 0) count++;
        }
        l++;
      }
      cout << "l is " << l << endl << endl;
    }
    string res = "";
    if (width <= len) res = s.substr(p, width);
    return res;
  }
};

int main() {
  //   string s = "adobecodebanc";
  //   string t = "abc";
  string s = "aaaa";
  string t = "a";
  Solution sol;
  string res = sol.minWindow(s, t);
  cout << "res is " << res << endl;
  return 0;
}