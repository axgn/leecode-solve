#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
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

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
