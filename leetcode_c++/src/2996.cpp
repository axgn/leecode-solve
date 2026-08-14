#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int missingInteger(vector<int> &nums) {
    int sum = nums[0];
    int i = 1;
    for (; i < nums.size() && nums[i] == nums[i - 1] + 1; i++) {
      sum += nums[i];
    }

    unordered_set<int> s(nums.begin() + i - 1, nums.end());
    while (s.contains(sum)) {
      sum++;
    }
    return sum;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
