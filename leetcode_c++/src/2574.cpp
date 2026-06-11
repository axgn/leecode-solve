#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> leftRightDifference(vector<int> &nums) {
    int n = nums.size();
    vector<int> leftSum(n + 1);
    for (int i = 1; i <= n; i++) {
      leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }
    int sum = leftSum[n];
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      int left = leftSum[i];
      int right = sum - leftSum[i] - nums[i];
      res[i] = abs(left - right);
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
