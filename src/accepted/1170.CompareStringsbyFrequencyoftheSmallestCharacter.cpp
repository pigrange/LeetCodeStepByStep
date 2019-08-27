#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> numSmallerByFrequency(vector<string>& queries,
                                    vector<string>& words) {
    vector<int> res, ref;
    for (auto w : words) ref.push_back(getFrequency(w));
    sort(ref.begin(), ref.end());
    for (auto i : queries) {
      int slen = getFrequency(i);
      int j = ref.size() - 1;
      while (j >= 0) {
        if (slen >= ref[j]) break;
        j--;
      }
      res.push_back(ref.size() - j);
    }
    return res;
  }

 private:
  int getFrequency(string& str) {
    sort(str.begin(), str.end());
    int i = 0;
    for (; i < str.size(); i++) {
      if (i < str.size() - 1 && str[i] != str[i + 1]) return i + 1;
    }
    return i;
  }
};