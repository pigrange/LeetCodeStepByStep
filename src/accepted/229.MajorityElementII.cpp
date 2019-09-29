#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
    for (auto i : nums) {
      if (num1 == i) {
        count1++;
      } else if (num2 == i) {
        count2++;
      } else if (count1 == 0) {
        num1 = i;
        count1 = 1;
      } else if (count2 == 0) {
        num2 = i;
        count2 = 1;
      }else{
        count1--;
        count2--;
      }
    }
    count1 = 0;
    count2 = 0;
    for (auto i : nums) {
      if (i == num1) count1++;
      //这个else 很有灵性
      else if (i == num2) count2++;
    }
    vector<int> res;
    if (count1 > nums.size() / 3) res.push_back(num1);
    if (count2 > nums.size() / 3) res.push_back(num2);
    return res;
  }
};