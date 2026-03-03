#include <bits/stdc++.h>
#include <cstddef>
#include <ios>
#include <vector>

using namespace std;

class Solution {
private:
  bool result = false;
  size_t word_i = 0;
  size_t right;
  size_t bottom;
  void bfs(size_t i, size_t j, vector<vector<char>> &board, string &word,
           vector<vector<bool>> &is_used) {
    if (board[i][j] == word[word_i] && !is_used[i][j]) {
      word_i++;
      is_used[i][j] = true;
      if (i < bottom - 1) {
        bfs(i + 1, j, board, word, is_used);
      }
      if (i > 0) {
        bfs(i - 1, j, board, word, is_used);
      }
      if (j > 0) {
        bfs(i, j - 1, board, word, is_used);
      }
      if (j < right - 1) {
        bfs(i, j + 1, board, word, is_used);
      }
      is_used[i][j] = false;
      word_i--;
    } else {
      return;
    }
    if (word_i == word.size() - 1) {
      result = true;
      return;
    }
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    bottom = board.size(), right = board[0].size();
    vector<vector<bool>> is_used(bottom, vector<bool>(right));
    for (size_t i = 0; i < bottom; i++) {
      for (size_t j = 0; j < right; j++) {
        bfs(i, j, board, word, is_used);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  cout << boolalpha << s.exist(board, word) << endl;
  return 0;
}
