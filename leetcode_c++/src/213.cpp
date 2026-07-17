#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
  vector<int> cache;
  // Todo: add start and end to optimize code
  int dfs(int i, vector<int> &nums) {
    if (i < 0) {
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
  int rob1(vector<int> &nums) {
    int n = nums.size();
    cache.assign(n, -1);
    return dfs(n - 1, nums);
  }
  int rob(vector<int> &nums) {
    if (nums.size() <= 2) {
      return ranges::max(nums);
    }
    vector<int> nums1(nums.begin() + 2, nums.end() - 1);
    vector<int> nums2(nums.begin() + 1, nums.end());
    return max(rob1(nums1) + nums[0], rob1(nums2));
  }
};
int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 1};
  s.rob(nums);
  cout << "" << "\n";
  return 0;
}
