#include <iostream>
#include <vector>
using namespace std;

//很烂的回溯
class Solution {
  vector<int> ref;
  int pos = 0;
  string res;

 public:
  string getPermutation(int n, int k) {
    ref = vector<int>(n + 1, 0);
    solve("", 0, 1, n, k);
    return res;
  }

 private:
  bool solve(string current, int depth, int start, int n, int k) {
    if (depth == n) {
      pos += 1;
      if (pos == k) {
        res = current;
        return true;
      }
      return false;
    }
    for (int i = start; i <= n; i++) {
      if (ref[i]) continue;
      ref[i] = 1;
      current.push_back(i + '0');
      if (solve(current, depth + 1, i + 1, n, k)) return true;
      ref[i] = 0;
      current.pop_back();
    }
    return false;
  }
};
//奢华的解法
class Solution {
 public:
  string getPermutation(int n, int k) {
    string res;
    vector<bool> st(n, false);
    for (int i = 0; i < n; i++) {
      int f = 1;
      for (int j = 1; j <= n - i - 1; j++) f *= j;  //计算 (n-i-1)!
      int next = 0;
      if (k > f) {
        int t = k / f;
        k %= f;
        if (k == 0) k = f, t--;
        while (t) {
          if (!st[next]) t--;
          next++;
        }
      }
      while (st[next]) next++;
      res += to_string(next + 1);
      st[next] = true;
    }

    return res;
  }
};

//奢华的解法2
class Solution {
 public:
  string getPermutation(int n, int k) {
    int pTable = n, temp;
    vector<char> numSet(n, '1');
    for (int i = 1; i < n; i++) {
      pTable *= i;
      numSet[i] = numSet[i - 1] + 1;
    }
    string res;
    while (n > 0) {
      pTable /= n;
      temp = (k - 1) / pTable;
      res += numSet[temp];
      numSet.erase(numSet.begin() + temp);
      k -= temp * pTable;
      n--;
    }
    return res;
  }
};

int main() {
  Solution sol;
  cout << sol.getPermutation(4, 9) << endl;
  return 0;
}