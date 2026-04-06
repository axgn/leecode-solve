#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n);
    if (n == 1) {
      return nums[0];
    }
    dp[0] = nums[0];
    dp[1] = nums[1];
    if (n == 2) {
      return max(dp[n - 1], dp[n - 2]);
    }
    dp[2] = nums[0] + nums[2];
    for (int i = 3; i < n; i++) {
      dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
    }
    return max(dp[n - 1], dp[n - 2]);
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
