#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int minMoves(vector<int> &nums, int limit) {
    vector<int> diff(2 * limit + 2);
    int n = nums.size();
    for (int i = 0; i < n / 2; i++) {
      int x = nums[i], y = nums[n - 1 - i];
      int min_v = min(x, y);
      int max_v = max(x, y);
      diff[2] += 2;
      diff[min_v + 1] -= 1;
      diff[x + y] -= 1;
      diff[x + y + 1] += 1;
      diff[max_v + limit + 1] += 1;
      diff[2 * limit + 1] -= 2;
    }
    int min = INT_MAX;
    for (int i = 2; i <= 2 * limit; i++) {
      diff[i] += diff[i - 1];
      if (diff[i] < min) {
        min = diff[i];
      }
    }
    return min;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
