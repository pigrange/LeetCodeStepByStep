#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    if (haystack.size() == 0) return -1;
    char flag = needle[0];
    string substr;
    for (int i = 0; i < haystack.size(); i++) {
      if (haystack[i] == flag) {
        substr = haystack.substr(i, needle.size());
        if (substr == needle) return i;
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int strStr(string haystack, string needle) {
    int hlen = haystack.size(), nlen = needle.size();
    for (int i = 0; i <= hlen - nlen; i++) {
      int j = 0;
      for (; j < nlen; j++) {
        if (haystack[i + j] != needle[j]) {
          break;
        }
      }
      if (j == nlen) return i;
    }
    return -1;
  }
};

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) return 0;
    if (haystack.size() == 0) return -1;
    int hlen = haystack.size(), nlen = needle.size();
    int flag = 0;
    for (int i = 0; i < hlen; i++) {
      flag = 1;
      for (int j = 0; j < nlen; j++) {
        if (haystack[i + j] != needle[j]) {
          flag = 0;
          break;
        }
      }
      if (flag) return i;
    }
    return -1;
  }
};