#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    nums.push_back(INT_MIN);
    int mid = 0;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (nums[mid] < nums[mid + 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 1};
  Solution s;
  cout << s.findPeakElement(nums) << "\n";
  return 0;
}
