#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> ref, ref1;
    for (auto i : arr) {
      ref[i]++;
    }
    for (auto i : ref) {
      int val = i.second;
      if (ref1.count(val)) return false;
      ref1[val] = 1;
    }
    return true;
  }
};