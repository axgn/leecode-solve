#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
  vector<int> cache;
  int dfs(int i, vector<int> &nums) {
    if (i <= 0) {
      return 0;
    }
    if (cache[i] != -1) {
      return cache[i];
    }
    int value = max(dfs(i - 1, nums), dfs(i - 2, nums) + nums[i]);
    cache[i] = value;
    return value;
  }

public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    cache.assign(n + 1, -1);
    return dfs(n, nums);
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
