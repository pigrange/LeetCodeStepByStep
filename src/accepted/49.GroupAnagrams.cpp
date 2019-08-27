#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;

    for (auto& str : strs) {
      string s = str;
      sort(begin(s), end(s));
      map[s].push_back(move(str));
    }

    vector<vector<string>> result;
    for (auto& kv : map) result.push_back(move(kv.second));

    return result;
  }
};