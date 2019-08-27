#include <iostream>
using namespace std;

void quickSort(int nums[], int l, int r) {
  if (r <= l) return;
  int temp = nums[l], start = l, end = r;
  while (l < r) {
    while (nums[r] >= temp && l < r) r--;
    if (l < r) nums[l++] = nums[r];
    while (nums[l] <= temp && l < r) l++;
    if (l < r) nums[r--] = nums[l];
  }
  nums[l] = temp;
  quickSort(nums, start, l - 1);
  quickSort(nums, l + 1, end);
}

int main() {
  int nums[] = {72, 6, 57, 88, 60, 42, 83, 73, 48, 85};
  quickSort(nums, 0, 9);
  for (int i = 0; i < 9; i++) {
    cout << nums[i] << ",";
  }
  return 0;
}