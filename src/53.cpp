#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
// 左侧子段和，右侧子段和，最大子段和，整段和
using namespace std;
class Solution {
  struct Statu {
    int LeftSub;
    int RightSub;
    int Sub;
    int Sum;
  };
  Statu getStatu(vector<int> &nums, int left, int right) {
    if (left == right) {
      return {nums[left], nums[left], nums[left], nums[left]};
    }
    int mid = (left + right) / 2;
    Statu leftStatu = {nums[left], nums[left], nums[left], nums[left]};
    Statu rightStatu = {nums[right], nums[right], nums[right], nums[right]};
    if (left < mid) {
      leftStatu = getStatu(nums, left, mid);
    }
    if (right > mid + 1) {
      rightStatu = getStatu(nums, mid + 1, right);
    }
    int nextLeftSub =
        max(leftStatu.LeftSub, leftStatu.Sum + rightStatu.LeftSub);
    int nextRightSub =
        max(rightStatu.RightSub, rightStatu.Sum + leftStatu.RightSub);
    int nextSum = leftStatu.Sum + rightStatu.Sum;
    int nextSub = max(max(leftStatu.Sub, rightStatu.Sub),
                      leftStatu.RightSub + rightStatu.LeftSub);
    return {nextLeftSub, nextRightSub, nextSub, nextSum};
  }

public:
  int maxSubArray(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    int result = getStatu(nums, left, right).Sub;
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v = {1};
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << '\n';
  int result = s.maxSubArray(v);
  cout << result << "\n";
  return 0;
}
