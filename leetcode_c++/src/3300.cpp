#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
  int minElement(vector<int> &nums) {
    int minE = INT_MAX;
    for (auto &v : nums) {
      int temp = 0;
      while (v > 0) {
        temp += v % 10;
        v /= 10;
      }
      if (temp < minE) {
        minE = temp;
      }
    }
    return minE;
  }
};

int main() {
  Solution s;
  cout << "" << "\n";
  return 0;
}
