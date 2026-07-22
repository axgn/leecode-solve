#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = matrix[i][j] - '0';
          continue;
        }
        int temp = min({
            dp[i - 1][j - 1],
            dp[i][j - 1],
            dp[i - 1][j],
        });
        dp[i][j] = matrix[i][j] == '0' ? 0 : temp + 1;
      }
    }
    int max_e = INT_MIN;
    for (auto &v : dp) {
      for (auto &e : v) {
        max_e = max(max_e, e);
      }
    }
    return max_e * max_e;
  }
};
int main() {
  Solution s;
  vector<vector<char>> vv = {{'1', '0', '1', '0', '0'},
                             {'1', '0', '1', '1', '1'},
                             {'1', '1', '1', '1', '1'},
                             {'1', '0', '0', '1', '0'}};
  for (auto &v : vv) {
    ranges::copy(v, ostream_iterator<int>(cout, " "));
    cout << "\n";
  }
  cout << s.maximalSquare(vv) << "\n";
  return 0;
}
