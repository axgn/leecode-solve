#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxTotalValue(vector<int> &nums, int k) {
    int min = INT_MAX, max = INT_MIN;
    for (auto i : nums) {
      if (i < min) {
        min = i;
      }
      if (i > max) {
        max = i;
      }
    }
    return (long long)(max - min) * k;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
