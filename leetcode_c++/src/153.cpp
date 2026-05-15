#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    int l_v = nums[left], r_v = nums[right];
    while (left < right) {
      int mid = (left + right) / 2;
      if (nums[mid] > l_v) {
        left = mid;
      }
      if (nums[mid] < r_v) {
        right = mid;
      }
    }
    return nums[left];
  }
};

int main() {
  Solution s;
  vector<int> nums = {4, 5, 7, 1, 2, 3};
  cout << s.findMin(nums) << "\n";
  return 0;
}
