#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int largestInteger(vector<int> &nums, int k) {
    unordered_map<int, int> cnt;
    ranges::for_each(nums, [&](int a) { cnt[a]++; });
    if (k == nums.size()) {
      int max = INT_MIN;
      ranges::for_each(cnt, [&](const pair<int, int> &a) {
        max = max > a.first ? max : a.first;
      });
      return max;
    }
    if (k > 1) {
      if (cnt[nums[0]] > 1 && cnt[nums.back()] > 1) {
        return -1;
      }
      if (cnt[nums[0]] > 1) {
        return nums.back();
      }
      if (cnt[nums.back()] > 1) {
        return nums[0];
        
      }
      return max(nums[0], nums.back());
    }
    int max = INT_MIN;
    ranges::for_each(cnt, [&](const pair<int, int> &a) {
      if (a.second == 1) {
        max = max > a.first ? max : a.first;
      }
    });
    if (max == INT_MIN) {
      return -1;
    }
    return max;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
