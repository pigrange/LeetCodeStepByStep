#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int solve(int humans, int ship) {
    // pair<int, int> shore1(humans, humans), shore2(0, 0);
    vector<vector<int>> ref = {{humans, humans}, {0, 0}};
    this->shipCount = ship;
    this->goal = humans;
    unordered_set<int> set;
    vector<vector<vector<int>>> path;
    find(ref, 0, set, path);
    int res = this->res;
    return res;
  }

 private:
  int goal = 0;
  int shipCount = 0;
  int res = 0;

  void find(vector<vector<int>>& ref, int dir, unordered_set<int>& went,
            vector<vector<vector<int>>>& path) {
    //出现了重复的情况
    int hash_code = hash(ref, dir);
    if (went.count(hash_code)) {
      return;
    }

    //考虑传教士少于野人的情况
    if (ref[0][0] > 0 && ref[0][0] < ref[0][1]) {
      // cout << ref[0][0] << "<" << ref[0][1] << endl;
      return;
    }
    if (ref[1][0] > 0 && ref[1][0] < ref[1][1]) {
      // cout << ref[1][0] << "<" << ref[1][1] << endl;
      return;
    }

    went.insert(hash_code);
    path.push_back(ref);
    //找到解
    if (ref[1][0] == goal && ref[1][1] == goal) {
      //   cout << "Find res" << endl;
      for (auto step : path) {
        cout << "[ ";
        for (auto i : step[0]) cout << i << " ";
        cout << "] , ";
        cout << "[ ";
        for (auto i : step[1]) cout << i << " ";
        cout << "] " << endl;
      }
      cout << endl;
      this->res++;
      went.erase(hash_code);
      path.pop_back();
      return;
    }

    int next = (dir + 1) % 2;
    vector<int>& from = ref[dir];
    vector<int>& to = ref[next];
    for (int i = 0; i <= shipCount && i <= from[0]; i++) {
      for (int j = 0; j <= shipCount - i && j <= from[1]; j++) {
        if (i == 0 && j == 0) continue;
        //船上野人数量大于传教士的数量
        if (i > 0 && j > i) continue;
        from[0] -= i;
        from[1] -= j;
        to[0] += i;
        to[1] += j;
        find(ref, (dir + 1) % 2, went, path);
        from[0] += i;
        from[1] += j;
        to[0] -= i;
        to[1] -= j;
      }
    }
    went.erase(hash_code);
    path.pop_back();
  }

  int hash(vector<vector<int>>& ref, int dir) {
    int base[] = {11, 23, 31, 47, 59};
    int resval = ref[0][0] * base[0] + ref[0][1] * base[1] +
                 ref[1][0] * base[2] + ref[1][1] * base[3] + dir * base[4];
    return resval;
  }
};

int main() {
  Solution sol;
  int solve = sol.solve(5, 3);
  cout << solve << endl;
}