#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int res = A[0];
    for (int i = 1; i < A.size(); i++) {
      res = max(res, A[i]);
    }
    return res;
  }
};

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    int l = 0, r = A.size() - 1;
    while (l < r) {
      int mid = l + (l - r) / 2;
      if (A[mid] < A[mid + 1]) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};