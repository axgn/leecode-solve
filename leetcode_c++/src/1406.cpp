#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      dp[i] = INT_MIN;
      int sum = 0;
      for (int j = i; j < min(i + 3, n); j++) {
        sum += stoneValue[j];
        dp[i] = max(dp[i], sum - dp[j + 1]);
      }
    }
    if (dp[0] == 0) {
      return "Tie";
    } else if (dp[0] > 0) {
      return "Alice";
    } else {
      return "Bob";
    }
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
