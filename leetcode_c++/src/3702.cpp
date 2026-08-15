#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    bool check = false;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        check = true;
      }
      res = res ^ nums[i];
    }
    if (res != 0) {
      return n;
    } else {
      if (check) {
        return n - 1;
      } else {
        return 0;
      }
    }
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
