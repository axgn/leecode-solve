#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int left = -1, right = nums.size() - 1;
    while (left + 1 < right) {
      int mid = left + (right - left) / 2;
      (nums[mid] < nums.back() ? right : left) = mid;
    }
    return nums[right];
  }
};

int main() {
  Solution s;
  vector<int> nums = {4, 5, 7, 1, 2, 3};
  cout << s.findMin(nums) << "\n";
  return 0;
}
