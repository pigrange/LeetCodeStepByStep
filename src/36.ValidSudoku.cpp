#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    unordered_map<int, vector<int>> map;
    // m是大横坐标
    for (int m = 0; m < 9; m += 3) {
      // n是大纵坐标
      for (int n = 0; n < 9; n += 3) {
        //初始化一个全部为1的数组
        int ref[10] = {0};
        //一个三格*三格
        for (int x = m; x < m + 3; x++) {
          for (int y = n; y < n + 3; y++) {
            char num = board[y][x] - '0';
            if (num == -2) continue;
            //处理3*3格中不重复的情况
            if (ref[num] != 0) return false;
            ref[num] = 1;
            //处理整体的行列的不重复的情况；
            int pos = x + y * 9;
            vector<int> &bucket = map[num];
            for (int prePos : bucket) {
              if (pos / 9 == prePos / 9 || abs(pos - prePos) % 9 == 0)
                return false;
            }
            bucket.push_back(pos);
          }
        }
      }
    }
    return true;
  }
};

//别人的解法
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[i].size(); ++j)
        if (board[i][j] != '.') {
          int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
          if (used1[i][num] || used2[j][num] || used3[k][num]) return false;
          used1[i][num] = used2[j][num] = used3[k][num] = 1;
        }

    return true;
  }
};

int main() {
  vector<vector<char>> board = {{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
                                {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
                                {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
                                {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};

  Solution sol;
  bool res = sol.isValidSudoku(board);
  cout << "res is " << res << endl;
  return 0;
}