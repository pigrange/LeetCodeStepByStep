#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//我的
// class Solution {
//  public:
//   vector<int> findSubstring(string s, vector<string>& words) {
//     vector<int> res;
//     if (words.size() == 0) return res;
//     unordered_map<string, int> map, ref;
//     int wordLen = words[0].size(), wordCount = words.size(), slen = s.size(),
//         substrlen = wordCount * wordLen;
//     for (string s : words) map[s] = map[s] + 1;
//     for (int i = 0; i < wordLen; i++) {
//       int count = 0;
//       ref.clear();
//       for (int j = i; j <= slen - wordLen; j += wordLen) {
//         string tempword = s.substr(j, wordLen);
//         if (!map.count(tempword)) {
//           count = 0;
//           ref.clear();
//         } else {
//           count++;
//           ref[tempword] = ref[tempword] + 1;
//           //重复的单词数量超了,这种情况直接不考虑出现重复的单词里面的第一个
//           while (ref[tempword] > map[tempword]) {
//             //找到头字符串的位置，并收到减少count和ref[substr]
//             //这样间接使得滑动窗口移动
//             string substr = s.substr(j - (count - 1) * wordLen, wordLen);
//             count--;
//             ref[substr]--;
//           }
//           //如果count等于了wordCount的话，就说明满足了条件了
//           //问题是如何确定位置
//           //实际上和之前一样j-(count-1) * wordLen substr头的文字
//           if (count == wordCount) res.push_back(j - (count - 1) * wordLen);
//         }
//       }
//     }
//     return res;
//   }
// };

// //别人的
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int wordCount = words.size();
    int slen = s.size();
    vector<int> res;
    if (wordCount == 0 || slen == 0) return res;
    int wordLen = words[0].size();
    int count = wordCount;
    unordered_map<string, int> map;
    //初始化map
    map.clear();
    for (string s : words) map[s] = map[s] + 1;

    //外层循环控制分组遍历
    for (int start = 0; start < wordLen; start++) {
      int j = start;
      string str;
      for (int head = start; head <= slen - wordLen; head += wordLen) {
        j = j > head ? j : head;
        while (j <= slen - wordLen) {
          str = s.substr(j, wordLen);
          //如果存在这个str的key，并且要key对应的个数还有
          if (!map.count(str)) {
            j += wordLen;
            head = j;
            map.clear();
            for (string s : words) map[s] = map[s] + 1;
            count = wordCount;
          } else if (map[str] > 0) {
            map[str]--;
            count--;
            j += wordLen;
            if (count == 0) {
              res.push_back(head);
              break;
            }
          } else {
            break;
          }
        }
        //如果map中substr的一个个满足key，就是说明第一个是满足要求的。
        //将滑动窗口向右移动wordLen个长度
        if (map.count(s.substr(head, wordLen)) != 0) {
          map[s.substr(head, wordLen)]++;
          count++;
        }
      }
    }
    return res;
  }
};

// 别人的
//滑动窗口
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    if (0 == words.size()) return ans;
    // 统计单词数组中各单词出现的次数
    int wordLen = words[0].length();
    unordered_map<string, int> map;
    for (string s : words) map[s] = map[s] + 1;
    // L次利用滑动窗口查找(L表示单词长度)
    for (int i = 0; i < wordLen; ++i) {
      int count = 0;
      unordered_map<string, int> ref;
      for (int j = i; j < s.length(); j += wordLen) {
        string word = s.substr(j, wordLen);
        // 如果滑动窗口内的子串在单词数组中没有出现，那么之前的所有计数清空，重新开始计数
        if (map.count(word) != 1) {
          count = 0;
          ref.clear();
        }
        // 如果滑动窗口内的子串在单词数组中出现
        else {
          count++;
          ref[word] = ref[word] + 1;

          //出现了多余的单词
          while (ref[word] > map[word]) {
            string pre = s.substr(j - (count - 1) * wordLen, wordLen);
            count--;
            ref[pre]--;
          }

          if (words.size() == count) {
            ans.push_back(j - (count - 1) * wordLen);
          }
        }
      }
    }
    return ans;
  }
};

int main() {
  // string s = "barfoofoobarthefoobarman";
  // vector<string> words = {"bar", "foo", "the"};

  // string s = "abababab";
  // vector<string> words = {"a", "b", "a"};

  // string s = "wordgoodgoodgoodbestword";
  // vector<string> words = {"word", "good", "best", "good"};

  string s = "barfoothefoobarman";
  vector<string> words = {"bar", "foo"};
  Solution sol;
  vector<int> res = sol.findSubstring(s, words);
  for (int i : res) cout << i << " ";
  return 0;
}