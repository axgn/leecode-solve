#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  bool check(vector<int> &nums) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i] < nums[i - 1]) {
        cnt++;
      }
    }
    if (cnt == 1 && nums[n - 1] <= nums[0]) {
      return true;
    } else if (cnt == 0) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
