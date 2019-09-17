#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//没有做出来的错误解法
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    quickSort(nums, 0, nums.size() - 1);
    string res = "";
    for (int i = 0; i <= nums.size(); i++) {
      int num = nums[i];
      if (num == 0) {
        res.push_back('0');
        continue;
      }
      while (num > 0) {
        int ch = num % 10 + '0';
        res.push_back(ch);
        num = (num) / 10;
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }

 private:
  void quickSort(vector<int>& nums, int left, int right) {
    int l = left, r = right, t = nums[l];
    while (l < r) {
      while (l < r && compare(nums[r], t) != -1) r--;
      if (l < r) nums[l++] = nums[r];
      while (l < r && compare(nums[l], t) != 1) l++;
      if (l < r) nums[r--] = nums[l];
    }
    nums[l] = t;
    quickSort(nums, left, l - 1);
    quickSort(nums, l, right);
  }
  int compare(int num1, int num2) {
    if (num1 > 9 || num2 > 9) {
      int b = num1 > num2 ? 1 : -1;
      int big = max(num1, num2);
      int small = num1 + num2 - big;
      //拿val和1,11,111,1111比较大小
      int base = 1, bigc = (int)log10(big), smallc = (int)log10(small);
      int offset = bigc - smallc, mul = (int)pow(10, smallc + 1);
      for (int i = 0; i < offset; i++) {
        base = base * mul + 1;
      }
      base = base * (big / small);
      int res = big > base ? 1 : big == base ? 0 : -1;
      return res * b;
    }
    return num1 > num2 ? 1 : num1 < num2 ? -1 : 0;
  }
};

struct Comparator {
  bool operator()(const string& lhs, const string& rhs) {
    return lhs + rhs > rhs + lhs;
  }
};

class Solution {
 public:
  static bool customSortFunc(string n1, string n2) {
    return (n1 + n2) > (n2 + n1);
  }
  string largestNumber(vector<int>& arr) {
    int n = arr.size();

    vector<string> numbers;
    for (int i = 0; i < n; i++) numbers.push_back(to_string(arr[i]));

    sort(numbers.begin(), numbers.end(), customSortFunc);

    if (numbers[0] == "0") return "0";

    string ans = "";
    for (int i = 0; i < numbers.size(); i++) ans += numbers[i];

    return ans;
  }
};