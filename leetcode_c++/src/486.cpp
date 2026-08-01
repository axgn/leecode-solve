#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  bool predictTheWinner(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
      dp[i][i] = nums[i];
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    return dp[0][n - 1] >= 0;
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
