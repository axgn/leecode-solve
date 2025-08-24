#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  void sortColors(vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[start]);
        start++;
      }
    }
    for (int i = nums.size() - 1; i >= 0; i--) {
      if (nums[i] == 2) {
        swap(nums[i], nums[end]);
        end--;
      }
    }
  }
};
int main() {
  Solution s;
  vector<int> v = {2, 0, 2, 1, 1, 0};
  s.sortColors(v);
  ranges::copy(v, ostream_iterator<int>(cout, " "));
  cout << "" << endl;
  return 0;
}
