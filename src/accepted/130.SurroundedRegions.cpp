#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty()) return;
    int h = board.size(), w = board[0].size();
    vector<vector<int>> ref(h, vector<int>(w, 0));
    for (int i = 0; i < w; i++) {
      if (board[0][i] == 'O') dfs(i, 0, board, ref);
      if (board[h - 1][i] == 'O') dfs(i, h - 1, board, ref);
    }

    for (int i = 0; i < h; i++) {
      if (board[i][0] == 'O') dfs(0, i, board, ref);
      if (board[i][w - 1] == 'O') dfs(w - 1, i, board, ref);
    }
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (ref[y][x] != 1) board[y][x] = 'X';
      }
    }
  }

 private:
  void dfs(int x, int y, vector<vector<char>>& board,
           vector<vector<int>>& ref) {
    if (y >= board.size() || y < 0) return;
    if (x >= board[0].size() || x < 0) return;
    //非0则是走过的
    if (ref[y][x]) return;
    if (board[y][x] != 'O') {
      ref[y][x] = -1;
      return;
    }
    ref[y][x] = 1;
    dfs(x + 1, y, board, ref);
    dfs(x - 1, y, board, ref);
    dfs(x, y + 1, board, ref);
    dfs(x, y - 1, board, ref);
  }
};

int main() {
  vector<vector<char>> board = {{'X', 'O', 'X', 'X', 'X', 'O'},
                                {'O', 'X', 'O', 'X', 'O', 'X'},
                                {'X', 'O', 'X', 'X', 'X', 'O'},
                                {'O', 'X', 'O', 'X', 'O', 'X'}};
  Solution sol;
  sol.solve(board);
  for (auto line : board) {
    for (auto ch : line) cout << ch << " ";
    cout << endl;
  }
  return 0;
}