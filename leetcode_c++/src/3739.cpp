#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> sum(n + 1);
    unordered_map<int, int> sum_cnt;
    sum_cnt[0] = 1;
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + (nums[i] == target ? 1 : -1);
    }
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) {
      res[i] = sum[i] > sum[i - 1] ? res[i - 1] + sum_cnt[sum[i - 1]]
                                   : res[i - 1] - sum_cnt[sum[i]];
      sum_cnt[sum[i]]++;

      // 三个问题：1. 为什么要补充sum_cnt[0] = 1;2. res[i - 1] -
      // sum_cnt[sum[i]]，为什么是i而不是i-1;3. 为什么要先求值在统计次数
    }
    return reduce(res.begin(), res.end(), 0LL);
  };
};

class Solution2 {
public:
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    unordered_map<int, int> cnt = {{0, 1}};
    long long ans = 0;
    int s = 0, f = 0;
    for (int x : nums) {
      if (x == target) {
        f += cnt[s];
        s++;
      } else {
        s--;
        f -= cnt[s];
      }
      ans += f;
      cnt[s]++;
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 2, 3};
  cout << s.countMajoritySubarrays(nums, 2) << "\n";
  return 0;
}
