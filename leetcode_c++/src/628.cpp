#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
  int maximumProduct(vector<int> &nums) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
    for (auto &num : nums) {
      if (num > max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      } else if (num > max2) {
        max3 = max2;
        max2 = num;
      } else if (num > max3) {
        max3 = num;
      }
      if (num < min1) {
        min3 = min2;
        min2 = min1;
        min1 = num;
      } else if (num < min2) {
        min3 = min2;
        min2 = num;
      } else if (num < min3) {
        min3 = num;
      }
    }
    return max(max1 * max2 * max3, max1 * min1 * min2);
  }
};
int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
