#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 1;
    int cnt = 0;
    int n = nums.size();
    for (int fast = 1; fast < n; fast++) {
      if (nums[fast] == nums[fast - 1]) {
        cnt++;
      } else {
        cnt = 0;
      }
      if (cnt >= 2) {
        continue;
      }
      nums[slow] = nums[fast];
      slow++;
    }
    return slow;
  }
};
