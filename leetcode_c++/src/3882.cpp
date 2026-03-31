#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    int min = 1025;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<unordered_set<int>>> set_dp(m, vector<unordered_set<int>>(n));
    set_dp[0][0].insert(grid[0][0]);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        if (i > 0) {
          for (auto &temp : set_dp[i - 1][j]) {
            set_dp[i][j].insert(temp ^ grid[i][j]);
          }
        }

        if (j > 0) {
          for (auto &temp : set_dp[i][j - 1]) {
            set_dp[i][j].insert(temp ^ grid[i][j]);
          }
        }
      }
    }
    for (auto &temp : set_dp[m - 1][n - 1]) {
      if (temp < min) {
        min = temp;
      }
    }
    return min;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
