#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    int res = 0, res1 = 0, meet = 0, end = start;
    if (end < 0) end = end + distance.size();
    for (int i = start; !(i == end && meet);) {
      if (i == destination) {
        i = (i + 1) % distance.size();
        meet = 1;
      }
      if (!meet) {
        res += distance[i];
      } else {
        res1 += distance[i];
      }
      i = (i + 1) % distance.size();
    }
    return min(res, res1);
  }
};

class Solution {
 public:
  int distanceBetweenBusStops(vector<int>& distance, int start,
                              int destination) {
    int res1 = 0, res2 = 0;
    int len = distance.size();
    int s = start, d = destination;
    for (int i = s; i % len != d; i++) res1 += distance[i % len];
    for (int i = d; i % len != s; i++) res2 += distance[i % len];
    return min(res1, res2);
  }
};

int main() {
  //   vector<int> dis = {7, 10, 1, 12, 11, 14, 5, 0};
  vector<int> dis = {1, 2, 3, 4};
  Solution sol;
  int res = sol.distanceBetweenBusStops(dis, 1, 0);
  cout << res;
  return 0;
}