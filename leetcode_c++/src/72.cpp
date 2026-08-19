#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        int temp = dp[i - 1][j - 1];
        temp = word1[i - 1] != word2[j - 1] ? temp + 1 : temp;
        dp[i][j] = min({temp, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
      }
    }
    return dp[m][n];
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
