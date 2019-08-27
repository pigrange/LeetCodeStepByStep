#include <iostream>
#include <vector>
using namespace std;
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    char ch = word[0];
    bool res = false;
    for (int y = 0; y < board.size(); y++) {
      for (int x = 0; x < board[0].size(); x++) {
        if (board[y][x] == ch) res = res || solve(board, word, 0, y, x);
      }
    }
    return res;
  }

 private:
  bool solve(vector<vector<char>>& board, string word, int step, int y, int x) {
    if (step == word.size()) return true;
    if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size()) return false;
    if (board[y][x] != word[step]) return false;
    char ch = board[y][x];
    cout << ch << " ";
    board[y][x] = 0;
    bool res = solve(board, word, step + 1, y - 1, x) ||
               solve(board, word, step + 1, y + 1, x) ||
               solve(board, word, step + 1, y, x - 1) ||
               solve(board, word, step + 1, y, x + 1);
    board[y][x] = ch;
    return res;
  }
};