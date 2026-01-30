#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int i_size = grid.size();
    int j_size = grid[0].size();
    vector<vector<int>> dp(i_size, vector<int>(j_size));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < i_size; i++) {
      dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < j_size; j++) {
      dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < i_size; i++) {
      for (int j = 1; j < j_size; j++) {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
      }
    }
    return dp[i_size - 1][j_size - 1];
  }
};
int main() {
  Solution s;
  vector<vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  int a = s.minPathSum(matrix);
  cout << a << "\n";
  vector<vector<int>> dp(0, vector<int>(1));
  for (auto i : dp) {
    cout << i[0];
  }
  return 0;
}
