#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  // Todo: ReWrite again
  vector<int> pathsWithMaxScore(vector<string> &board) {
    constexpr int MOD = 1'000'000'007;
    int n = board.size();
    vector<vector<int>> scores(n + 1, vector<int>(n + 1, INT_MIN));
    vector<vector<int>> cnts(n + 1, vector<int>(n + 1));
    scores[0][0] = 0;
    cnts[0][0] = 1;
    for (int i = 0; i <= n - 1; i++) {
      for (int j = 0; j <= n - 1; j++) {
        char ch = board[i][j];
        if (ch == 'X') {
          continue;
        }
        scores[i + 1][j + 1] =
            max({scores[i][j], scores[i + 1][j], scores[i][j + 1]});
        int s = scores[i + 1][j + 1];
        long long cnt = 0;
        if (scores[i][j] == s) {
          cnt += cnts[i][j];
        }
        if (scores[i + 1][j] == s) {
          cnt += cnts[i + 1][j];
        }
        if (scores[i][j + 1] == s) {
          cnt += cnts[i][j + 1];
        }
        cnts[i + 1][j + 1] = cnt % MOD;
        if ('1' <= ch && ch <= '9') {
          scores[i + 1][j + 1] += ch - '0';
        }
      }
    }
    return scores[n][n] < 0 ? vector<int>{0, 0}
                            : vector<int>{scores[n][n], cnts[n][n]};
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
