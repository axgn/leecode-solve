#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution2 {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = i; j < n; j++) {
        target == nums[j] ? cnt++ : 0;
        cnt > (j - i + 1) / 2 ? result++ : 0;
      }
    }
    return result;
  }
};

class Solution {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + (nums[i] == target ? 1 : -1);
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        if (sum[i + 1] - sum[j] > 0) {
          result++;
        }
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
