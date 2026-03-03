#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> buildArray(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      int temp = nums[i];
      if (temp < 0) {
        continue;
      }
      int cur = i;
      while (nums[cur] != i) {
        int next = nums[cur];
        nums[cur] = ~nums[next];
        cur = next;
      }
      nums[cur] = ~temp;
    }
    for (int i = 0; i < nums.size(); i++) {
      nums[i] = ~nums[i];
    }
    return nums;
  }
};

int main() {
  Solution s;
  vector<int> nums = {5, 0, 2, 4, 3, 1};
  vector<int> v = s.buildArray(nums);
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << "" << endl;
  return 0;
}
