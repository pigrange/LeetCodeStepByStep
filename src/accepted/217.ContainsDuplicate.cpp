#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> ref;
    if (!nums.size()) return false;
    for (auto i : nums) {
      if (ref.count(i)) return true;
      ref.insert(i);
    }
    return false;
  }
};