#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    long total = 0;
    int temp = 0;
    int len = calories.size();
    for (int i = 1; i <= len; i++) {
      temp += calories[i - 1];
      if (i < k) {
        continue;
      }
      int score = temp > upper ? 1 : temp < lower ? -1 : 0;
      cout << "score :" << score << endl;
      total += score;
      temp -= calories[i - k];
    }
    // for (int i = 1; i <= left; i++) {
    //   temp += calories[i];
    //   int score = temp > upper ? 1 : temp < lower ? -1 : 0;
    //   total += score;
    // }
    return (int)total;
  }
};
// class Solution {
//  public:
//   int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper)
//   {
//     long total = 0;
//     int len = calories.size() / k * k;
//     cout << "len:" << len << endl;
//     int left = calories.size() - len;
//     int temp = 0;
//     for (int i = 1; i <= len; i++) {
//       temp += calories[i - 1];
//       if (i % k == 0) {
//         int score = temp > upper ? 1 : temp < lower ? -1 : 0;
//         cout << "score :" << score << endl;
//         total += score;
//         temp = 0;
//       }
//     }
//     for (int i = 1; i <= left; i++) {
//       temp += calories[i];
//       int score = temp > upper ? 1 : temp < lower ? -1 : 0;
//       total += score;
//     }
//     return (int)total;
//   }
// };

int main() {
  Solution sol;
  //   vector<int> calories = {1, 2, 3, 4, 5};
  //   vector<int> calories = {3,2};
  //   vector<int> calories = {6, 5, 0, 0};
  vector<int> calories = {6, 13, 8, 7, 10, 1, 12, 11};
  int res = sol.dietPlanPerformance(calories, 6, 5, 37);
  cout << res << endl;
  return 0;
}