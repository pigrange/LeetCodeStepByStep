#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//很炫酷的解法
class Solution {
 public:
  int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1, level = 0, water = 0;
    while (l < r) {
      int lower = height[height[l] < height[r] ? l++ : r--];
      level = max(level, lower);
      water += level - lower;
    }
    return water;
  }
};

class Solution {
 public:
  int trap(int A[], int n) {
    int left = 0;
    int right = n - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while (left <= right) {
      if (A[left] <= A[right]) {
        if (A[left] >= maxleft)
          maxleft = A[left];
        else
          res += maxleft - A[left];
        left++;
      } else {
        if (A[right] >= maxright)
          maxright = A[right];
        else
          res += maxright - A[right];
        right--;
      }
    }
    return res;
  }
};

// DP
class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() == 0) return 0;
    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
      left_max[i] = max(height[i], left_max[i - 1]);
    }
    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
      right_max[i] = max(height[i], right_max[i + 1]);
    }
    for (int i = 1; i < size - 1; i++) {
      ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
  }
};

//使用栈
class Solution {
 public:
  int trap(vector<int>& height) {
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
      while (!st.empty() && height[current] > height[st.top()]) {
        int top = st.top();
        st.pop();
        if (st.empty()) break;
        int distance = current - st.top() - 1;
        int bounded_height =
            min(height[current], height[st.top()]) - height[top];
        ans += distance * bounded_height;
      }
      st.push(current++);
    }
    return ans;
  }
};

//双指针
class Solution {
 public:
  int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        height[left] >= left_max ? (left_max = height[left])
                                 : ans += (left_max - height[left]);
        ++left;
      } else {
        height[right] >= right_max ? (right_max = height[right])
                                   : ans += (right_max - height[right]);
        --right;
      }
    }
    return ans;
  }
};

int main() {
  //   vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  //   vector<int> height = {5, 4, 1, 2};
  vector<int> height = {5, 2, 1, 1, 2, 5};
  Solution sol;
  int res = sol.trap(height);
  cout << "res is " << res;
  return 0;
}