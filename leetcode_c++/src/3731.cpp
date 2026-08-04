#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> findMissingElements(vector<int> &nums) {
    int *cnt = (int *)malloc(sizeof(int) * 101);
    memset(cnt, 0, 101 * sizeof(int));
    int min = 101, max = -1;
    for (auto &val : nums) {
      cnt[val] = 1;
      max = val > max ? val : max;
      min = val < min ? val : min;
    }
    vector<int> res;
    for (int i = min; i <= max; i++) {
      if (!cnt[i]) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
