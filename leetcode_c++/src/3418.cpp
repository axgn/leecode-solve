#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumAmount(vector<vector<int>> &coins) {
    int m = coins.size(), n = coins[0].size();
    vector<vector<array<int, 3>>> dp(m,
                                     vector<array<int, 3>>(n, array<int, 3>()));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < 3; k++) {
          if (i == 0 && j == 0) {
            if (k == 0) {
              dp[i][j][k] = coins[i][j];
            } else {
              dp[i][j][k] = max(coins[i][j], 0);
            }
            continue;
          }
          if (i == 0) {
            if (k != 0) {
              dp[i][j][k] =
                  max({dp[i][j - 1][k] + coins[i][j], dp[i][j - 1][k - 1]});
            } else {
              dp[i][j][k] = dp[i][j - 1][k] + coins[i][j];
            }
            continue;
          }
          if (j == 0) {
            if (k != 0) {
              dp[i][j][k] =
                  max({dp[i - 1][j][k] + coins[i][j], dp[i - 1][j][k - 1]});
            } else {
              dp[i][j][k] = dp[i - 1][j][k] + coins[i][j];
            }
            continue;
          }
          if (k != 0) {
            dp[i][j][k] =
                max({dp[i - 1][j][k] + coins[i][j], dp[i - 1][j][k - 1],
                     dp[i][j - 1][k] + coins[i][j], dp[i][j - 1][k - 1]});
          } else {
            dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]) + coins[i][j];
          }
        }
      }
    }

    return dp[m - 1][n - 1][2];
  }
};

int main() {
  Solution s;
  vector<vector<int>> coins = {{1, 2, 3}, {2, 3, 4}};
  cout << s.maximumAmount(coins) << "\n";
  return 0;
}
