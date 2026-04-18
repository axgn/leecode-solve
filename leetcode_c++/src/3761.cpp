#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

public:
  int reverseNum(int number) {
    int res = 0;
    while (number > 0) {
      int temp = number % 10;
      number /= 10;
      res = res * 10 + temp;
    }
    return res;
  }
  int minMirrorPairDistance(vector<int> &nums) {
    std::unordered_map<int, int> val_pos;
    int res = INT_MAX;
    int n = nums.size();
    for (int i = n - 1; i >= 0; i--) {
      int rNum = reverseNum(nums[i]);
      if (val_pos.contains(rNum)) {
        res = min(res, val_pos[rNum] - i);
      }
      val_pos[nums[i]] = i;
    }
    return res == INT_MAX ? -1 : res;
  }
};

int main() {
  Solution s;
  cout << s.reverseNum(210) << "\n";
  return 0;
}
