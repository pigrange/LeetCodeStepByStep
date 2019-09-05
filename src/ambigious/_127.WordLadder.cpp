#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
//比较容易理解的解法
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dist(wordList.begin(), wordList.end());
    unordered_map<string, int> m;
    m[beginWord] = 1;
    queue<string> todo;
    todo.push(beginWord);
    while (!todo.empty()) {
      string word = todo.front();
      todo.pop();
      for (int i = 0; i < word.size(); ++i) {
        string newword = word;
        //更改一个字符，并测试是否在wordlist里面是否存在
        //即找出word可达且在wordlist里面的所有newword
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          newword[i] = ch;
          //如果wordlist里面没有newword直接contunue;
          if (!dist.count(newword)) continue;
          //找到了newword，并且直接等于endword的时候，直接返回
          if (newword == endWord) return m[word] + 1;
          //找到了newword并且m中没有出现过，即说明没有重复使用
          if (!m.count(newword)) {
            todo.push(newword);
            m[newword] = m[word] + 1;
          }
        }
      }
    }
    return 0;
  }
};

//下面稍微做了一下优化。快不少
class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (!wordSet.count(endWord)) return 0;
    queue<string> q{{beginWord}};
    int res = 0;
    while (!q.empty()) {
      //这里初始化k=q.size() 很巧秒，因为后面q的大小会变化
      //所以预先获取q的大小，避免了之后q添加元素后,调用q.size()值不断变化
      for (int k = q.size(); k > 0; --k) {
        string word = q.front();
        q.pop();
        if (word == endWord) return res + 1;
        for (int i = 0; i < word.size(); ++i) {
          string newWord = word;
          for (char ch = 'a'; ch <= 'z'; ++ch) {
            newWord[i] = ch;
            if (wordSet.count(newWord) && newWord != word) {
              q.push(newWord);
              //之前是用的map来看单词是否被使用过的。。。
              wordSet.erase(newWord);
            }
          }
        }
      }
      //每个单词，表示一步，就是一层
      ++res;
    }
    return 0;
  }
};