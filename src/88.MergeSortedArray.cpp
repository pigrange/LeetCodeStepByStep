#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = nums1.size();
    reverse(nums1.begin(), nums1.begin() + m);
    reverse(nums1.begin(), nums1.end());
    int p1 = len - m, p2 = 0, p = 0;
    while (p1 < len && p2 < n) {
      if (nums1[p1] < nums2[p2])
        nums1[p++] = nums1[p1++];
      else
        nums1[p++] = nums2[p2++];
    }
    if (p2 < n) {
      while (p2 < n) nums1[p++] = nums2[p2++];
    } else {
      while (p1 < len) nums1[p++] = nums1[p1++];
    }
  }
};

//神仙解法啊！！！
//注意，两个升序数组的合并从后往前啊啊啊！！！
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, tar = m + n - 1;
    while (j >= 0) {
      nums1[tar--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
  }
};