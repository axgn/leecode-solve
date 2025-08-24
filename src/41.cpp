#include <bits/stdc++.h>
#include <cstdlib>
#include <ostream>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int result = nums.size() + 1;
    int max = result;
    for (auto &num : nums) {
      if (num <= 0) {
        num = max;
      }
    }
    for (int i = 0; i < (int)nums.size(); i++) {
      int pos = abs(nums[i]) - 1;
      if (pos >= 0 && pos < (int)nums.size() && nums[pos] > 0) {
        nums[pos] = -nums[pos];
      }
    }
    for (auto i = nums.begin(); i != nums.end(); i++) {
      if (*i > 0) {
        result = i - nums.begin() + 1;
        break;
      }
    }
    return result;
  }
};

class Solution2 {
public:
  int firstMissingPositive(vector<int> &nums) {
    int result = nums.size() + 1;
    for (int i = 0; i < (int)nums.size(); i++) {
      int pos = nums[i] - 1;
      while (pos >= 0 && pos < (int)nums.size() && nums[pos] != nums[i]) {
        int temp = nums[pos];
        nums[pos] = nums[i];
        nums[i] = temp;
        pos = nums[i] - 1;
      }
    }
    for (int i = 0; i < (int)nums.size(); i++) {
      if (nums[i] != i + 1) {
        result = i + 1;
      }
    }
    return result;
  }
};

int main() {
  Solution2 s;
  vector<int> v = {1};
  cout << s.firstMissingPositive(v) << ' ' << flush;
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  return 0;
}
